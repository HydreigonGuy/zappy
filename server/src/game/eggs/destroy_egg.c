/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_egg
*/

#include "server.h"
#include <stdlib.h>

void destroy_egg(egg_t *egg, egg_t **eggs)
{
    egg_t *tmp = *eggs;

    if (tmp == egg) {
        *eggs = tmp->next;
        if (!tmp->con)
            free(tmp->crds);
        free(tmp);
        return;
    }
    for (; tmp->next && tmp->next != egg; tmp = tmp->next);
    if (!tmp->next)
        return;
    tmp->next = tmp->next->next;
    if (!egg->con)
        free(egg->crds);
    free(egg);
}
