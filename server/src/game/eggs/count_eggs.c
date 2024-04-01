/*
** EPITECH PROJECT, 2022
** server
** File description:
** count_eggs
*/

#include "server.h"

int count_eggs(egg_t *eggs)
{
    int size = 0;

    for (egg_t *curr = eggs; curr; curr = curr->next)
        if (!curr->con)
            size++;
    return (size);
}
