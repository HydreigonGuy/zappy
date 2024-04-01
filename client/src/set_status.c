/*
** EPITECH PROJECT, 2022
** client
** File description:
** set_status
*/

#include "client.h"

void set_status(client_t *client)
{
    if (client->status == WRITE) {
        client->status = READ;
        return;
    }
    client->status = READ;
    if (client->write_buff)
        client->status = WRITE;
}
