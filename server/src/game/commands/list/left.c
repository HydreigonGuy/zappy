/*
** EPITECH PROJECT, 2022
** server
** File description:
** left
*/

#include "server.h"

void left(player_t *player, connection_t *con, connection_t *all)
{
    player->crds->facing = (player->crds->facing + 1) % 4;
    create_buff(&con->write_buff, "ok\n");
    send_gui_player_moved(all, player);
}
