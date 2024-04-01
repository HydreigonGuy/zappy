/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_food_spawn
*/

#include "server.h"

void handle_food_spawn(map_t *map)
{
    map->cooldown--;
    if (map->cooldown <= 0) {
        fill_map_contents(map);
        refresh_map_contents(map);
        map->cooldown = FOOD_REFRESH;
    }
}
