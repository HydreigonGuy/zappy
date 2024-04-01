/*
** EPITECH PROJECT, 2022
** server
** File description:
** eject
*/

#include "server.h"
#include <stdio.h>

void eject_player(player_t *player, int direction, map_t *map)
{
    if (direction == FACING_DOWN)
        player->crds->y = (player->crds->y + 1) % map->heigth;
    if (direction == FACING_UP)
        player->crds->y = (player->crds->y - 1 + map->heigth) % map->heigth;
    if (direction == FACING_RIGHT)
        player->crds->x = (player->crds->x + 1) % map->width;
    if (direction == FACING_LEFT)
        player->crds->x = (player->crds->x - 1 + map->width) % map->width;
}

void eject(connection_t *con, game_data_t *data, connection_t *all)
{
    int moved = 0;
    char resp[20] = {'\0'};

    for (connection_t *curr = all; curr; curr = curr->next)
        if (curr->player && curr->player != con->player &&
        curr->player->crds->x == con->player->crds->x && curr->player->crds->y
        == con->player->crds->y) {
            eject_player(curr->player, con->player->crds->facing, data->map);
            sprintf(resp, "eject: %i\n\0", get_broadcast_k(con->player->crds,
            curr->player->crds, data->map));
            create_buff(&curr->write_buff, resp);
            moved = 1;
        }
    if (!moved)
        create_buff(&con->write_buff, "ko\n");
    else
        create_buff(&con->write_buff, "ok\n");
}
