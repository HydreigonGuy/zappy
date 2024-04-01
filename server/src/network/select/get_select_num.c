/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_select_num
*/

#include "server.h"

int get_select_num(int server, connection_t *con)
{
    int ret = server;

    for (connection_t *curr = con; curr; curr = curr->next)
        if (curr->fd > ret)
            ret = curr->fd;
    return (ret + 1);
}
