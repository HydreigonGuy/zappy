/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_all_tiles
*/

#include "server.h"
#include <stdio.h>

void send_gui_time_info(connection_t *con, int i, game_data_t *data)
{
    game_tile_t *tile = data->map->tiles[i];
    char resp[70] = {'\0'};

    sprintf(resp, "{%i, %i, %i, %i, %i, %i, %i, %i, %i, %i}",
    i % data->map->width, i / data->map->width, tile->contents->food,
    tile->contents->linemate, tile->contents->deraumere,
    tile->contents->sibur, tile->contents->mendiane,
    tile->contents->phiras, tile->contents->thystame,
    count_players_on_crds(data->players, i % data->map->width,
    i / data->map->width));
    create_buff(&con->write_buff, resp);
}

void send_gui_all_tiles(connection_t *con, game_data_t *data)
{
    create_buff(&con->write_buff, "50 [\0");
    for (int i = 0; data->map->tiles[i]; i++)
        send_gui_time_info(con, i, data);
    create_buff(&con->write_buff, "] tiles info\n\0");
}
