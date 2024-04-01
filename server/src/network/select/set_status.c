/*
** EPITECH PROJECT, 2022
** server
** File description:
** set_status
*/

#include "server.h"

void change_status(connection_t *connect)
{
    if (connect->status == DEAD)
        return;
    if (connect->status == WRITE) {
        connect->status = READ;
        return;
    }
    connect->status = READ;
    if (connect->write_buff)
        connect->status = WRITE;
}

void set_status(connection_t *connect)
{
    for (connection_t *curr = connect; curr; curr = curr->next)
        change_status(curr);
}
