/*
** EPITECH PROJECT, 2022
** server
** File description:
** set_all_unready
*/

#include "server.h"

void set_all_unready(server_t *server, connection_t *connect)
{
    server->can_accept = 0;
    for (connection_t *curr = connect; curr; curr = curr->next)
        curr->ready = 0;
}
