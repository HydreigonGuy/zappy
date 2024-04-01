/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_connection
*/

#include "server.h"
#include <stddef.h>
#include <stdlib.h>

connection_t *create_new_connection(int fd)
{
    connection_t *new = malloc(sizeof(connection_t));

    if (!new)
        return (NULL);
    new->read_buff = NULL;
    new->write_buff = NULL;
    new->fd = fd;
    new->status = READ;
    new->ready = 0;
    new->next = NULL;
    new->player = NULL;
    new->gui_con = 0;
    create_buff(&new->write_buff, "WELCOME\n");
    return (new);
}

void create_connection(connection_t **connect, int fd)
{
    connection_t *curr = *connect;

    if (!curr) {
        *connect = create_new_connection(fd);
        return;
    }
    for (; curr && curr->next; curr = curr->next);
    curr->next = create_new_connection(fd);
}
