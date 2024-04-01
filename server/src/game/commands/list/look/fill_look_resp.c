/*
** EPITECH PROJECT, 2022
** server
** File description:
** fill_look_resp
*/

#include "server.h"
#include <string.h>

void get_tile_look(int x, int y, game_data_t *data, char *resp)
{
    game_tile_t *tile = get_tile(data->map, x, y);
    int player_c = count_players_on_crds(data->players, x, y);

    for (int i = 0; i < tile->contents->deraumere; i++)
        strcat(resp, " deraumere");
    for (int i = 0; i < tile->contents->food; i++)
        strcat(resp, " food");
    for (int i = 0; i < tile->contents->linemate; i++)
        strcat(resp, " linemate");
    for (int i = 0; i < tile->contents->mendiane; i++)
        strcat(resp, " mendiane");
    for (int i = 0; i < tile->contents->phiras; i++)
        strcat(resp, " phiras");
    for (int i = 0; i < tile->contents->sibur; i++)
        strcat(resp, " sibur");
    for (int i = 0; i < tile->contents->thystame; i++)
        strcat(resp, " thystame");
    for (int i = 0; i < player_c; i++)
        strcat(resp, " player");
}

void get_level_look(int level, crds_t *crds, game_data_t *data, char *resp)
{
    for (int i = 0; i < level * 2 + 1; i++) {
        if (crds->facing == FACING_UP)
            get_tile_look(crds->x - level + i, crds->y - level,
            data, resp);
        if (crds->facing == FACING_DOWN)
            get_tile_look(crds->x + level - i, crds->y + level,
            data, resp);
        if (crds->facing == FACING_LEFT)
            get_tile_look(crds->x - level, crds->y + level - i,
            data, resp);
        if (crds->facing == FACING_RIGHT)
            get_tile_look(crds->x + level, crds->y - level + i,
            data, resp);
        strcat(resp, ",");
    }
}

void fill_look_resp(int level, crds_t *crds, game_data_t *data, char *resp)
{
    resp[0] = '[';
    for (int i = 0; i <= level; i++) {
        get_level_look(i, crds, data, resp);
    }
    resp[strlen(resp) - 1] = '\0';
    strcat(resp, "]\n");
}
