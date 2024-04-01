/*
** EPITECH PROJECT, 2022
** server
** File description:
** init_gui_connection
*/

#include "server.h"
#include <stdio.h>

void send_gui_map_size(connection_t *con, map_t *map)
{
    char resp[40] = {'\0'};

    sprintf(resp, "10 [%i,%i] Sending map size\n\0",
    map->width, map->heigth);
    create_buff(&con->write_buff, resp);
}

void init_gui_connection(connection_t *con, game_data_t *data)
{
    con->gui_con = 1;
    send_gui_map_size(con, data->map);
    send_gui_teams_list(con, data->teams);
    for (player_list_t *curr = data->players; curr; curr = curr->next)
        send_gui_player_con(con, curr->player->id, curr->player->crds);
}
