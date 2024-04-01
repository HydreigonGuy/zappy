/*
** EPITECH PROJECT, 2022
** client
** File description:
** fill_client_info
*/

#include "client.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void fill_client_info(client_t *client, int port, char *ip)
{
    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    client->address.sin_family = AF_INET;
    client->address.sin_port = htons(port);
    inet_aton(ip, (struct in_addr *) &client->address.sin_addr.s_addr);
    client->read_buff = NULL;
    client->write_buff = NULL;
    client->ready = 0;
    client->shutdown = 0;
    client->status = READ;
}
