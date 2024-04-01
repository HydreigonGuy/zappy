/*
** EPITECH PROJECT, 2022
** server
** File description:
** broadcast
*/

#include "server.h"
#include <string.h>
#include <stdio.h>

void send_broadcast(char *msg, connection_t *con, crds_t *sender, map_t *map)
{
    int k = get_broadcast_k(sender, con->player->crds, map);
    char resp[20 + strlen(msg)];

    sprintf(resp, "message %i, %s\0", k, msg);
    create_buff(&con->write_buff, resp);
}

void broadcast(char *msg, connection_t *con, connection_t *all, map_t *map)
{
    create_buff(&con->write_buff, "ok\n");
    for (connection_t *curr = all; curr; curr = curr->next) {
        if (curr->player && curr != con)
            send_broadcast(msg, curr, con->player->crds, map);
        if (curr->gui_con)
            send_gui_broadcast(curr, con->player, msg);
    }
}
