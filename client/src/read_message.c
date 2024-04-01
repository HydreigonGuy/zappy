/*
** EPITECH PROJECT, 2022
** client
** File description:
** read_message
*/

#include "client.h"

void read_message(client_t *client)
{
    if (client->status == READ && client->ready == 1) {
        if (!read_socket(client->socket, &client->read_buff))
            client->status = DISCONNECTED;
        client->ready = 0;
    }
}
