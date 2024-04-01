/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_elevation_starts
*/

#include "server.h"

void broadcast_elevation_start(connection_t *con, connection_t *all)
{
    for (connection_t *curr = all; curr; curr = curr->next) {
        if (curr->player && curr->player->level == con->player->level &&
            curr->player->crds->x == con->player->crds->x &&
            curr->player->crds->y == con->player->crds->y)
            create_buff(&curr->write_buff, "Elevation underway\n");
        if (curr->gui_con)
            send_gui_elvtn_start(curr, con->player);
    }
}

void handle_elevation_starts_con(game_data_t *data, connection_t *con,
connection_t *all)
{
    int valid = check_for_valid_elevation(con, data);

    if (!valid) {
        destroy_command(&con->player->commands);
        create_buff(&con->write_buff, "ko\n");
    } else {
        broadcast_elevation_start(con, all);
    }
}

void handle_elevation_starts(game_data_t *data, connection_t *connects)
{
    for (connection_t *curr = connects; curr; curr = curr->next)
        if (curr->player && curr->player->commands &&
        curr->player->commands->incantation == 299)
            handle_elevation_starts_con(data, curr, connects);
}
