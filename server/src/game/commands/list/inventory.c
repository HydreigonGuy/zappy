/*
** EPITECH PROJECT, 2022
** server
** File description:
** inventory
*/

#include "server.h"
#include <stdio.h>

void inventory(player_t *player, connection_t *con)
{
    char buff[200] = {'\0'};

    sprintf(buff, "[food %i, linemate %i, deraumere %i, sibur %i, mendiane %i, phiras %i, thystame %i]\n\0",
    player->inventory->food,
    player->inventory->linemate,
    player->inventory->deraumere,
    player->inventory->sibur,
    player->inventory->mendiane,
    player->inventory->phiras,
    player->inventory->thystame);
    create_buff(&con->write_buff, buff);
}
