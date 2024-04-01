/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_connections
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>

void destroy_connections(connection_t **connect, game_data_t *data)
{
    connection_t *tmp = *connect;

    while (tmp) {
        close_connection(tmp, data, *connect);
        *connect = tmp->next;
        free(tmp);
        tmp = *connect;
    }
}
