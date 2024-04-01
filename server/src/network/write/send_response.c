/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_response
*/

#include "server.h"

void send_response(connection_t *connect)
{
    for (connection_t *curr = connect; curr; curr = curr->next) {
        if ((curr->status == WRITE || curr->status == DEAD) &&
            curr->ready) {
            write_on_socket(curr->fd, &curr->write_buff);
            curr->ready = 0;
        }
    }
}
