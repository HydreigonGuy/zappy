/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_teams
*/

#include "server.h"
#include <stdlib.h>

void destroy_teams(team_t *teams)
{
    team_t *tmp = teams;

    for (; tmp;) {
        teams = teams->next;
        free(tmp);
        tmp = teams;
    }
}
