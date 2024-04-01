/*
** EPITECH PROJECT, 2022
** server
** File description:
** close_connection
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>

void close_connection(connection_t *connect, game_data_t *data,
connection_t *all)
{
    if (connect->player)
        destroy_player(connect->player, data, all);
    close(connect->fd);
    destroy_all_buffers(connect->read_buff);
    destroy_all_buffers(connect->write_buff);
}
