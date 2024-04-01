/*
** EPITECH PROJECT, 2022
** client
** File description:
** send_response
*/

#include "client.h"

void send_response(client_t *client)
{
    if (client->status == WRITE && client->ready == 1) {
        write_on_socket(client->socket, &client->write_buff);
        client->ready = 0;
    }
}
