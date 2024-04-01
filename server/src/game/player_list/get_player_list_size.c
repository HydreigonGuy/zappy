/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_player_list_size
*/

#include "server.h"

int get_player_list_size(player_list_t *list)
{
    int size = 0;

    for (player_list_t *curr = list; curr; curr = curr->next)
        size++;
    return (size);
}
