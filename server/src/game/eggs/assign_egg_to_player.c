/*
** EPITECH PROJECT, 2022
** server
** File description:
** assign_egg_to_player
*/

#include "server.h"
#include <stdlib.h>

void assign_egg_to_player(connection_t *con, egg_t *eggs)
{
    for (egg_t *curr = eggs; curr; curr = curr->next)
        if (!curr->con) {
            curr->con = con;
            return;
        }
}
