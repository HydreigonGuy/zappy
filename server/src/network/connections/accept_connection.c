/*
** EPITECH PROJECT, 2022
** server
** File description:
** accept_connection
*/

#include "server.h"

int accept_connection(server_t *server)
{
    int addr_len = sizeof(server->address);
    int client_socket = accept(server->server_socket,
        (struct sockaddr *) &server->address, (unsigned int *) &addr_len);

    if (client_socket == -1)
        return (0);
    return (client_socket);
}
