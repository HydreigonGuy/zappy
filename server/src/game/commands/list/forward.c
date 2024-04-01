/*
** EPITECH PROJECT, 2022
** server
** File description:
** forward
*/

#include "server.h"

void forward(player_t *player, connection_t *con, map_t *map,
connection_t *all)
{
    if (player->crds->facing == FACING_DOWN)
        player->crds->y = (player->crds->y + 1) % map->heigth;
    if (player->crds->facing == FACING_UP)
        player->crds->y = (player->crds->y - 1 + map->heigth) % map->heigth;
    if (player->crds->facing == FACING_RIGHT)
        player->crds->x = (player->crds->x + 1) % map->width;
    if (player->crds->facing == FACING_LEFT)
        player->crds->x = (player->crds->x - 1 + map->width) % map->width;
    create_buff(&con->write_buff, "ok\n");
    send_gui_player_moved(all, player);
}
