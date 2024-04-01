/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_command
*/

#include "server.h"
#include <stdlib.h>

command_t *new_command(char *command)
{
    command_t *new = malloc(sizeof(command_t));

    if (!new)
        return (NULL);
    new->command_str = command;
    new->incantation = -1;
    new->next = NULL;
    new->started = 0;
    return (new);
}

void create_command(command_t **commands, char *command)
{
    command_t *tmp = *commands;

    if (!tmp)
        *commands = new_command(command);
    else {
        for (; tmp && tmp->next; tmp = tmp->next);
        tmp->next = new_command(command);
    }
}
