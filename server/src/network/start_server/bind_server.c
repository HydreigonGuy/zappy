/*
** EPITECH PROJECT, 2022
** server
** File description:
** bind_server
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>

int bind_server(server_t *server)
{
    if (bind(server->server_socket, (struct sockaddr *) &server->address,
    sizeof(server->address)) == -1) {
        close(server->server_socket);
        free(server);
        return (0);
    }
    return (1);
}
