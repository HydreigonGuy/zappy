/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_selecting
*/

#include "client.h"

void handle_selecting(client_t *client)
{
    set_status(client);
    check_select(client);
    send_response(client);
    read_message(client);
    if (client->ready == 2)
        client->status = DISCONNECTED;
}
