/*
** EPITECH PROJECT, 2022
** server
** File description:
** add_team
*/

#include "server.h"
#include <stdlib.h>

team_t *create_team(char *name)
{
    team_t *new = malloc(sizeof(team_t));

    if (!new)
        return (NULL);
    new->next = NULL;
    new->players = NULL;
    new->name = name;
    new->eggs = NULL;
    return (new);
}

void add_team(team_t **teams, char *name)
{
    team_t *tmp = *teams;

    if (!tmp) {
        *teams = create_team(name);
    } else {
        for (; tmp && tmp->next; tmp = tmp->next);
        tmp->next = create_team(name);
    }
}
