/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_server
*/

#include "server.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

server_t *create_server(int port)
{
    server_t *new = malloc(sizeof(server_t));

    if (!new)
        return (NULL);
    new->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    new->address.sin_family = AF_INET;
    new->address.sin_port = htons(port);
    inet_aton("127.0.0.1", (struct in_addr *) &new->address.sin_addr.s_addr);
    new->stdin_ready = 0;
    new->can_accept = 0;
    return (new);
}
