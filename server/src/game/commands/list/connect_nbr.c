/*
** EPITECH PROJECT, 2022
** server
** File description:
** connect_nbr
*/

#include "server.h"
#include <stdio.h>

void connect_nbr(connection_t *con, game_data_t *data)
{
    char resp[6] = {'\0'};
    team_t *team = get_player_team(data->teams, con->player);

    if (!team)
        return;
    sprintf(resp, "%i\n\0", data->client_num -
        get_player_list_size(team->players) + count_eggs(team->eggs));
    create_buff(&con->write_buff, resp);
}
