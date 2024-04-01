/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_egg
*/

#include "server.h"
#include <stdlib.h>

egg_t *new_egg(crds_t *crds)
{
    egg_t *new = malloc(sizeof(egg_t));

    if (!new)
        return (NULL);
    new->crds = new_crds(1, 1);
    if (!new->crds) {
        free(new);
        return (NULL);
    }
    new->next = NULL;
    new->time = 0;
    new->crds->x = crds->x;
    new->crds->y = crds->y;
    new->crds->facing = rand() % 4;
    new->con = NULL;
    new->id = create_id();
    return (new);
}

egg_t *create_egg(egg_t **eggs, crds_t *crds)
{
    egg_t *tmp = *eggs;

    if (!tmp) {
        *eggs = new_egg(crds);
        return (*eggs);
    }
    for (; tmp && tmp->next; tmp = tmp->next);
    tmp->next = new_egg(crds);
    return (tmp->next);
}
