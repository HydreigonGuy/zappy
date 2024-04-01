/*
** EPITECH PROJECT, 2022
** server
** File description:
** check_player_in_list
*/

#include "server.h"

int check_player_in_list(player_t *player, player_list_t *list)
{
    for (player_list_t *curr = list; curr; curr = curr->next)
        if (curr->player == player)
            return (1);
    return (0);
}
