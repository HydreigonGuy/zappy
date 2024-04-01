/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_player_info
*/

#include "server.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

void send_gui_s_player_info(connection_t *con, player_t *player)
{
    char resp[100] = {'\0'};

    sprintf(resp, "260 [%i, %i, %i, %i, %i, %i, %i, %i, %i] player info\n\0",
    player->crds->facing, player->inventory->food,
    player->inventory->linemate, player->inventory->deraumere,
    player->inventory->sibur, player->inventory->mendiane,
    player->inventory->phiras, player->inventory->thystame,
    player->level);
    create_buff(&con->write_buff, resp);
}

void send_gui_player_info(connection_t *con, game_data_t *data, char *cmd)
{
    for (; cmd[0] && cmd[0] != '['; cmd = &cmd[1]);
    if (!cmd[0])
        return;
    cmd = &cmd[1];
    for (player_list_t *curr = data->players; curr; curr = curr->next)
        if (strncmp(cmd, curr->player->id, strlen(curr->player->id)) == 0)
            send_gui_s_player_info(con, curr->player);
}
