/*
** EPITECH PROJECT, 2022
** server
** File description:
** fill_map_data
*/

#include "server.h"
#include <stdlib.h>

void fill_map_data(map_t *map)
{
    map->tiles = malloc(sizeof(game_tile_t *) * (map->heigth * map->width
    + 1));
    if (!map->tiles)
        return;
    for (int i = 0; i < map->heigth * map->width; i++) {
        map->tiles[i] = malloc(sizeof(game_tile_t));
        if (!map->tiles[i]) {
            free(map->tiles);
            map->tiles = NULL;
            return;
        }
        map->tiles[i]->contents = new_contents();
        if (!map->tiles[i]->contents) {
            free(map->tiles);
            map->tiles = NULL;
            return;
        }
    }
    map->tiles[map->heigth * map->width] = NULL;
    fill_map_contents(map);
}
