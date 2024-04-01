/*
** EPITECH PROJECT, 2022
** server
** File description:
** check_if_team_name
*/

#include "server.h"
#include <string.h>

int check_if_team_name(char *name, team_t *teams)
{
    for (team_t *curr = teams; curr; curr = curr->next)
        if ((strncmp(name, curr->name, strlen(curr->name)) == 0) &&
            strlen(name) == strlen(curr->name) + 1)
            return (1);
    return (0);
}
