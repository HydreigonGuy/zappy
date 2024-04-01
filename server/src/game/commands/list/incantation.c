/*
** EPITECH PROJECT, 2022
** server
** File description:
** incantation
*/

#include "server.h"

void broadcast_elevation_end(connection_t *con, connection_t *all, char *resp)
{
    for (connection_t *curr = all; curr; curr = curr->next) {
        if (curr->player && curr->player->level == con->player->level &&
            curr->player->crds->x == con->player->crds->x &&
            curr->player->crds->y == con->player->crds->y)
            create_buff(&curr->write_buff, resp);
        if (curr->gui_con)
            send_gui_elvtn_res(curr, con->player->crds, 1);
    }
}

void level_up_players(player_list_t *players, crds_t *crds, int level)
{
    for (player_list_t *curr = players; curr; curr = curr->next)
        if (curr->player->crds->x == crds->x &&
        curr->player->crds->y == crds->y &&
        curr->player->level == level)
            curr->player->level++;
}

void send_gui_enc_end_failed(connection_t *all, crds_t *crds)
{
    for (connection_t *curr = all; curr; curr = curr->next)
        if (curr->gui_con)
            send_gui_elvtn_res(curr, crds, 0);
}

void incantation(connection_t *con, game_data_t *data, connection_t *all)
{
    int valid = check_for_valid_elevation(con, data);
    char resp[19] = "Current level: k\n\0";

    if (valid) {
        level_up_players(data->players, con->player->crds,
        con->player->level);
        resp[15] = '0' + con->player->level;
        broadcast_elevation_end(con, all, resp);
        delete_elevation_ressources(get_tile(data->map, con->player->crds->x,
        con->player->crds->y), con->player->level);
    } else {
        send_gui_enc_end_failed(all, con->player->crds);
        create_buff(&con->write_buff, "ko\n");
    }
}
