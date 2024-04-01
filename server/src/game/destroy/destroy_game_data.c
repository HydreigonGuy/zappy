/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_game_data
*/

#include "server.h"
#include <stdlib.h>

void destroy_game_data(game_data_t *data)
{
    destroy_teams(data->teams);
    for (int i = 0; data->map->tiles[i]; i++) {
        free(data->map->tiles[i]->contents);
        free(data->map->tiles[i]);
    }
    free(data->map);
    free(data);
}
