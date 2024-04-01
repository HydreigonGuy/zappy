/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_player_con
*/

#include "server.h"
#include <string.h>
#include <stdio.h>

void send_gui_player_con(connection_t *con, char *id, crds_t *crds)
{
    char resp[100] = {'\0'};

    sprintf(resp, "90 [-1, %s, %i, %i] sending player\n\0",
    id, crds->x, crds->y);
    create_buff(&con->write_buff, resp);
}
