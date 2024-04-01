/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_connection_ends
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>

void handle_connection_ends(connection_t **connect, game_data_t *data)
{
    connection_t *tmp = *connect;

    while (tmp && ((tmp->status == DEAD &&
    !tmp->write_buff)
    || tmp->status == DISCONNECTED)) {
        close_connection(tmp, data, *connect);
        *connect = tmp->next;
        free(tmp);
        tmp = *connect;
    }
    for (connection_t *curr = tmp; curr && curr->next; curr = curr->next) {
        if (curr->next->status == DISCONNECTED || (curr->next->status ==
        DEAD && !curr->next->write_buff)) {
            close_connection(curr->next, data, *connect);
            tmp = curr->next;
            curr->next = tmp->next;
            free(tmp);
        }
    }
}
