/*
** EPITECH PROJECT, 2022
** server
** File description:
** count_players_on_crds
*/

#include "server.h"

int count_players_on_crds(player_list_t *players, int x, int y)
{
    int ret = 0;

    for (player_list_t *curr = players; curr; curr = curr->next)
        if (curr->player->crds->x == x && curr->player->crds->y == y)
            ret++;
    return (ret);
}
