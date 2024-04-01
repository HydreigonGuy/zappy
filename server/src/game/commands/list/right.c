/*
** EPITECH PROJECT, 2022
** server
** File description:
** right
*/

#include "server.h"

void right(player_t *player, connection_t *con, connection_t *all)
{
    player->crds->facing--;
    if (player->crds->facing < 0)
        player->crds->facing += 4;
    create_buff(&con->write_buff, "ok\n");
    send_gui_player_moved(all, player);
}
