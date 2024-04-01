/*
** EPITECH PROJECT, 2022
** server
** File description:
** fill_map_cnts_list
*/

#include "server.h"
#include <stdlib.h>

int *fill_map_cnts_list(map_t *map)
{
    int *list = malloc(sizeof(int) * 7);

    if (!list)
        return (NULL);
    for (int i = 0; i < 7; list[i] = 0, i++);
    for (int i = 0; map->tiles[i]; i++) {
        list[0] += map->tiles[i]->contents->food;
        list[1] += map->tiles[i]->contents->linemate;
        list[2] += map->tiles[i]->contents->deraumere;
        list[3] += map->tiles[i]->contents->sibur;
        list[4] += map->tiles[i]->contents->mendiane;
        list[5] += map->tiles[i]->contents->phiras;
        list[6] += map->tiles[i]->contents->thystame;
    }
    return (list);
}
