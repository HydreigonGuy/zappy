/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_egg_laying
*/

#include "server.h"
#include <stdio.h>

void send_gui_egg_laying(connection_t *con, player_t *player, egg_t *egg)
{
    char resp[120] = {'\0'};

    sprintf(resp, "95 [%s, %s] layed an egg\n\0", player->id, egg->id);
    create_buff(&con->write_buff, resp);
}
