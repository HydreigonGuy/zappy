/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_broadcast
*/

#include "server.h"
#include <string.h>
#include <stdio.h>

void send_gui_broadcast(connection_t *con, player_t *player, char *msg)
{
    char resp[strlen(msg) + 60];

    sprintf(resp, "80 [%s, %s] broadcast\n\0",
    player->id, msg);
    create_buff(&con->write_buff, resp);
}
