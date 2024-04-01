/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_command_len
*/

#include "server.h"

int get_command_len(command_t *commands)
{
    int c = 0;

    for (command_t *curr = commands; curr; curr = curr->next)
        c++;
    return (c);
}
