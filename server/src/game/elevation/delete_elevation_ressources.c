/*
** EPITECH PROJECT, 2022
** server
** File description:
** delete_elevation_ressources
*/

#include "server.h"

void delete_elevation_ressources2(game_tile_t *tile, int level)
{
    if (level == 6)
        tile->contents->mendiane -= 3;
    if (level == 8)
        tile->contents->mendiane -= 2;
    if (level == 4 || level == 8)
        tile->contents->phiras -= 2;
    if (level == 5 || level == 7)
        tile->contents->phiras--;
    if (level == 8)
        tile->contents->thystame--;
}

void delete_elevation_ressources(game_tile_t *tile, int level)
{
    tile->contents->linemate--;
    if (level == 4 || level == 8)
        tile->contents->linemate--;
    if (level == 3 || level == 5)
        tile->contents->deraumere--;
    if (level == 6 || level == 7 || level == 8)
        tile->contents->deraumere -= 2;
    if (level == 3 || level == 4 || level == 6)
        tile->contents->sibur--;
    if (level == 5 || level == 8)
        tile->contents->sibur -= 2;
    if (level == 7)
        tile->contents->sibur -= 3;
    delete_elevation_ressources2(tile, level);
}
