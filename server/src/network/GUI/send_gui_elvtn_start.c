/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_elvtn_start
*/

#include "server.h"
#include <stdio.h>

void send_gui_elvtn_start(connection_t *con, player_t *player)
{
    char resp[100] = {'\0'};

    sprintf(resp, "70 [%i, %i, %s] start of encantation\n\0",
    player->crds->x, player->crds->y, player->id);
    create_buff(&con->write_buff, resp);
}
