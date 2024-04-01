/*
** EPITECH PROJECT, 2022
** server
** File description:
** fill_map_contents
*/

#include "server.h"
#include <stdlib.h>

int calc_map_content_ratio(map_t *map)
{
    int existing = 0;
    float ratio = 0;

    for (int i = 0; map->tiles[i]; i++)
        existing += map->tiles[i]->contents->deraumere +
        map->tiles[i]->contents->food +
        map->tiles[i]->contents->linemate +
        map->tiles[i]->contents->mendiane +
        map->tiles[i]->contents->phiras +
        map->tiles[i]->contents->sibur +
        map->tiles[i]->contents->thystame;
    ratio = 1 - (existing / (map->heigth * map->width));
    if (ratio < 0)
        ratio = 0;
    return (ratio);
}

int generate_ressources(float ratio, float density)
{
    int chance = ratio * density * 100;

    if (rand() % 100 < chance)
        return (1);
    return (0);
}

void fill_map_contents(map_t *map)
{
    float ratio = calc_map_content_ratio(map);

    for (int i = 0; map->tiles[i]; i++) {
        map->tiles[i]->contents->deraumere += generate_ressources(ratio,
        DERA_DENSITY);
        map->tiles[i]->contents->food += generate_ressources(ratio,
        FOOD_DENSITY);
        map->tiles[i]->contents->linemate += generate_ressources(ratio,
        LINE_DENSITY);
        map->tiles[i]->contents->mendiane += generate_ressources(ratio,
        MEND_DENSITY);
        map->tiles[i]->contents->phiras += generate_ressources(ratio,
        PHIR_DENSITY);
        map->tiles[i]->contents->sibur += generate_ressources(ratio,
        SIBU_DENSITY);
        map->tiles[i]->contents->thystame += generate_ressources(ratio,
        THYS_DENSITY);
    }
}
