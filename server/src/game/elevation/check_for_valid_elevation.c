/*
** EPITECH PROJECT, 2022
** server
** File description:
** check_for_valid_elevation
*/

#include "server.h"

int check_elevation_players(game_data_t *data, player_t *player)
{
    int count = 0;

    for (player_list_t *curr = data->players; curr; curr = curr->next)
        if (curr->player->crds->x == player->crds->x &&
        curr->player->crds->y == player->crds->y &&
        curr->player->level == player->level)
            count++;
    if (player->level == 1 && count == 1)
        return (1);
    if ((player->level == 2 || player->level == 3) && count == 2)
        return (1);
    if ((player->level == 4 || player->level == 5) && count == 4)
        return (1);
    if ((player->level == 6 || player->level == 7) && count == 6)
        return (1);
    return (0);
}

int check_for_valid_elevation2(connection_t *con, game_data_t *data,
game_tile_t *tile)
{
    if (con->player->level == 6 && (tile->contents->linemate < 1 ||
    tile->contents->deraumere < 2 || tile->contents->sibur < 3 ||
    tile->contents->phiras < 1))
        return (0);
    if (con->player->level == 7 && (tile->contents->linemate < 2 ||
    tile->contents->deraumere < 2 || tile->contents->sibur < 2 ||
    tile->contents->mendiane < 2 || tile->contents->phiras < 2 ||
    tile->contents->thystame < 1))
        return (0);
    if (!check_elevation_players(data, con->player))
        return (0);
    return (1);
}

int check_for_valid_elevation(connection_t *con, game_data_t *data)
{
    game_tile_t *tile = get_tile(data->map, con->player->crds->x,
    con->player->crds->y);

    if (con->player->level == 1 && (tile->contents->linemate < 1))
        return (0);
    if (con->player->level == 2 && (tile->contents->linemate < 1 ||
    tile->contents->deraumere < 1 || tile->contents->sibur < 1))
        return (0);
    if (con->player->level == 3 && (tile->contents->linemate < 2 ||
    tile->contents->sibur < 1 || tile->contents->phiras < 2))
        return (0);
    if (con->player->level == 4 && (tile->contents->linemate < 1 ||
    tile->contents->deraumere < 1 || tile->contents->sibur < 2 ||
    tile->contents->phiras < 1))
        return (0);
    if (con->player->level == 5 && (tile->contents->linemate < 1 ||
    tile->contents->deraumere < 2 || tile->contents->sibur < 1 ||
    tile->contents->mendiane < 3))
        return (0);
    return (check_for_valid_elevation2(con, data, tile));
}
