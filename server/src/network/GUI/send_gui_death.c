/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_death
*/

#include "server.h"
#include <stdio.h>

void send_gui_death(connection_t *con, player_t *player)
{
    char resp[70] = {'\0'};

    sprintf(resp, "200 [%s] player death\n\0", player->id);
    create_buff(&con->write_buff, resp);
}
