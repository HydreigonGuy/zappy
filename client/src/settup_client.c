/*
** EPITECH PROJECT, 2022
** client
** File description:
** settup_client
*/

#include "client.h"
#include <unistd.h>
#include <stdlib.h>

client_t *settup_client(int port, char *ip)
{
    client_t *client = malloc(sizeof(client_t));

    if (!client)
        return (NULL);
    fill_client_info(client, port, ip);
    if (connect(client->socket, (struct sockaddr *) &client->address,
        sizeof(client->address)) == -1) {
        close(client->socket);
        free(client);
        return (NULL);
    }
    return (client);
}
