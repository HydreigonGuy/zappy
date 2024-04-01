/*
** EPITECH PROJECT, 2022
** server
** File description:
** init_player
*/

#include "server.h"
#include <stdio.h>
#include <string.h>

int insert_new_player(connection_t *connect, game_data_t *data, team_t *team)
{
    char resp[50] = {'\0'};
    int cons_left = data->client_num + count_eggs(team->eggs) - 1 -
    get_player_list_size(team->players);

    if (cons_left < 0)
        cons_left = 0;
    add_player_to_list(connect->player, &data->players);
    add_player_to_list(connect->player, &team->players);
    sprintf(resp, "%i\n%i %i\n\0", cons_left, data->map->width,
    data->map->heigth);
    create_buff(&connect->write_buff, resp);
    return (0);
}

int init_and_send_player(connection_t *connect, game_data_t *data,
team_t *team, connection_t *all)
{
    for (connection_t *curr = all; curr; curr = curr->next)
        if (curr->gui_con)
            send_gui_player_con(curr, connect->player->id,
            connect->player->crds);
    return (insert_new_player(connect, data, team));
}

int init_player(connection_t *connect, char *team_name, game_data_t *data,
connection_t *all)
{
    team_t *team = NULL;

    for (team_t *curr = data->teams; curr; curr = curr->next)
        if (strncmp(team_name, curr->name, strlen(curr->name)) == 0 &&
            strlen(team_name) == strlen(curr->name) + 1)
            team = curr;
    if (!team || (get_player_list_size(team->players) >= data->client_num &&
    count_eggs(team->eggs) == 0)) {
        connect->status = DEAD;
        create_buff(&connect->write_buff,
        "Max number of connections reached for this team\n");
        return (0);
    } if (get_player_list_size(team->players) >= data->client_num) {
        assign_egg_to_player(connect, team->eggs);
        return (1);
    }
    connect->player = new_player(data);
    if (!connect->player)
        return (0);
    return (init_and_send_player(connect, data, team, all));
}
