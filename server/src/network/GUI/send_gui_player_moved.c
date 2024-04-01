/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_player_moved
*/

#include "server.h"
#include <stdio.h>

void send_gui_player_moved(connection_t *all, player_t *player)
{
    char resp[100] = {'\0'};

    sprintf(resp, "220 [%s, %i, %i, %i] player movement\n\0",
    player->id, player->crds->x, player->crds->y, player->crds->facing);
    for (connection_t *curr = all; curr; curr = curr->next)
        if (curr->gui_con)
            create_buff(&curr->write_buff, resp);
}
