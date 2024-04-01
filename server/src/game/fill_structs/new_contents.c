/*
** EPITECH PROJECT, 2022
** server
** File description:
** new_contents
*/

#include "server.h"
#include <stdlib.h>

contents_t *new_contents(void)
{
    contents_t *new = malloc(sizeof(contents_t));

    if (!new)
        return (NULL);
    new->deraumere = 0;
    new->food = 0;
    new->linemate = 0;
    new->mendiane = 0;
    new->phiras = 0;
    new->sibur = 0;
    new->thystame = 0;
    return (new);
}
