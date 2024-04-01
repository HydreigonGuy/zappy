/*
** EPITECH PROJECT, 2022
** server
** File description:
** read_message
*/

#include "server.h"

static void handle_reading_individual_msg(connection_t *connection)
{
    if (connection->status == READ && connection->ready) {
        if (!read_socket(connection->fd, &connection->read_buff))
            connection->status = DISCONNECTED;
    }
}

void read_message(connection_t *connect)
{
    for (connection_t *curr = connect; curr; curr = curr->next)
        handle_reading_individual_msg(curr);
}
