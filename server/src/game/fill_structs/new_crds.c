/*
** EPITECH PROJECT, 2022
** server
** File description:
** new_crds
*/

#include "server.h"
#include <stdlib.h>

crds_t *new_crds(int max_width, int max_height)
{
    crds_t *new = malloc(sizeof(crds_t));

    if (!new)
        return (NULL);
    new->facing = rand() % 4;
    new->x = rand() % max_width;
    new->y = rand() % max_height;
    return (new);
}
