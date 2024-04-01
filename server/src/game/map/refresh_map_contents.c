/*
** EPITECH PROJECT, 2022
** server
** File description:
** refresh_map_contents
*/

#include "server.h"
#include <stdlib.h>

void refresh_map_contents2(map_t *map, int *cnts_list)
{
    for (; cnts_list[3] < map->width * map->heigth * SIBU_DENSITY;
        cnts_list[3]++)
        get_tile(map, rand() % map->width,
            rand() % map->heigth)->contents->sibur++;
    for (; cnts_list[4] < map->width * map->heigth * MEND_DENSITY;
        cnts_list[4]++)
        get_tile(map, rand() % map->width,
            rand() % map->heigth)->contents->mendiane++;
    for (; cnts_list[5] < map->width * map->heigth * PHIR_DENSITY;
        cnts_list[5]++)
        get_tile(map, rand() % map->width,
            rand() % map->heigth)->contents->phiras++;
    for (; cnts_list[6] < map->width * map->heigth * THYS_DENSITY;
        cnts_list[6]++)
        get_tile(map, rand() % map->width,
            rand() % map->heigth)->contents->thystame++;
}

void refresh_map_contents(map_t *map)
{
    int *cnts_list = fill_map_cnts_list(map);

    if (!cnts_list)
        return;
    for (; cnts_list[0] < map->width * map->heigth * FOOD_DENSITY;
        cnts_list[0]++)
        get_tile(map, rand() % map->width,
            rand() % map->heigth)->contents->food++;
    for (; cnts_list[1] < map->width * map->heigth * LINE_DENSITY;
        cnts_list[1]++)
        get_tile(map, rand() % map->width,
            rand() % map->heigth)->contents->linemate++;
    for (; cnts_list[2] < map->width * map->heigth * DERA_DENSITY;
        cnts_list[2]++)
        get_tile(map, rand() % map->width,
            rand() % map->heigth)->contents->deraumere++;
    refresh_map_contents2(map, cnts_list);
    free(cnts_list);
}
