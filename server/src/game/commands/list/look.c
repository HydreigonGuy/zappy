/*
** EPITECH PROJECT, 2022
** server
** File description:
** look
*/

#include "server.h"
#include <stdlib.h>

void look(player_t *player, connection_t *con, game_data_t *data)
{
    int len = get_look_resp_len(player->level, player->crds, data);
    char *resp = malloc(sizeof(char) * (len + 1));

    if (!resp)
        return;
    for (int i = 0; i < len + 1; i++)
        resp[i] = '\0';
    fill_look_resp(player->level, player->crds, data, resp);
    create_buff(&con->write_buff, resp);
    free(resp);
}
