/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_win
*/

#include "server.h"
#include <stdio.h>

int check_for_win(team_t *team)
{
    int maxed = 0;

    for (player_list_t *curr = team->players; curr; curr = curr->next)
        if (curr->player->level == 8)
            maxed++;
    if (maxed >= 6)
        return (1);
    return (0);
}

void handle_win(game_data_t *data)
{
    for (team_t *curr = data->teams; curr; curr = curr->next)
        if (check_for_win(curr))
            printf("VICTORY! Team %s has WON!\n", curr->name);
}
