/*
** EPITECH PROJECT, 2022
** server
** File description:
** new_map
*/

#include "server.h"
#include <stdlib.h>

map_t *new_map(void)
{
    map_t *new = malloc(sizeof(map_t));

    if (!new)
        return (NULL);
    new->width = DEFAULT_WIDTH;
    new->heigth = DEFAULT_HEIGHT;
    new->tiles = NULL;
    new->cooldown = FOOD_REFRESH;
    return (new);
}
