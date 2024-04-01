/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_look_resp_len
*/

#include "server.h"

int get_tile_look_len(int x, int y, game_data_t *data)
{
    game_tile_t *tile = get_tile(data->map, x, y);
    int ret = 1;

    ret += tile->contents->deraumere * 10;
    ret += tile->contents->food * 5;
    ret += tile->contents->linemate * 9;
    ret += tile->contents->mendiane * 9;
    ret += tile->contents->phiras * 7;
    ret += tile->contents->sibur * 6;
    ret += tile->contents->thystame * 9;
    ret += count_players_on_crds(data->players, x, y) * 7;
    return (ret);
}

int get_level_look_len(int level, crds_t *crds, game_data_t *data)
{
    int ret = 0;

    for (int i = 0; i < level * 2 + 1; i++) {
        if (crds->facing == FACING_UP)
            ret += get_tile_look_len(crds->x - level + i, crds->y - level,
            data);
        if (crds->facing == FACING_DOWN)
            ret += get_tile_look_len(crds->x + level - i, crds->y + level,
            data);
        if (crds->facing == FACING_LEFT)
            ret += get_tile_look_len(crds->x - level, crds->y + level - i,
            data);
        if (crds->facing == FACING_RIGHT)
            ret += get_tile_look_len(crds->x + level, crds->y - level + i,
            data);
    }
    return (ret);
}

int get_look_resp_len(int level, crds_t *crds, game_data_t *data)
{
    int ret = 4;

    for (int i = 0; i <= level; i++) {
        ret += get_level_look_len(i, crds, data);
    }
    return (ret);
}
