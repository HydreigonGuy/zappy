/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_player_team
*/

#include "server.h"
#include <stddef.h>

team_t *get_player_team(team_t *teams, player_t *player)
{
    for (team_t *curr = teams; curr; curr = curr->next)
        if (check_player_in_list(player, curr->players))
            return (curr);
    return (NULL);
}
