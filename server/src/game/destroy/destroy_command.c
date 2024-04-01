/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_command
*/

#include "server.h"
#include <stdlib.h>

void destroy_command(command_t **cmd)
{
    command_t *tmp = *cmd;

    *cmd = tmp->next;
    free(tmp->command_str);
    free(tmp);
}
