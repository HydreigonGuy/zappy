/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_tile
*/

#include "server.h"

game_tile_t *get_tile(map_t *map, int x, int y)
{
    for (; x < 0; x += map->width);
    for (; y < 0; y += map->heigth);
    x = (x) % map->width;
    y = (y) % map->heigth;
    return (map->tiles[x + (y * map->width)]);
}
