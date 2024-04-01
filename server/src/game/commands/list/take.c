/*
** EPITECH PROJECT, 2022
** server
** File description:
** take
*/

#include "server.h"
#include <string.h>

void take3(char *obj, connection_t *con, game_tile_t *tile, connection_t *all)
{
    if (strcmp(obj, "thystame\n") == 0 && tile->contents->thystame > 0) {
        tile->contents->thystame--;
        con->player->inventory->thystame++;
        create_buff(&con->write_buff, "ok\n");
        send_all_gui_take(all, con->player->crds, 6);
        return;
    }
    if (strcmp(obj, "deraumere\n") == 0 && tile->contents->deraumere > 0) {
        tile->contents->deraumere--;
        con->player->inventory->deraumere++;
        create_buff(&con->write_buff, "ok\n");
        send_all_gui_take(all, con->player->crds, 2);
        return;
    }
    create_buff(&con->write_buff, "ko\n");
}

void take2(char *obj, connection_t *con, game_tile_t *tile, connection_t *all)
{
    if (strcmp(obj, "sibur\n") == 0 && tile->contents->sibur > 0) {
        tile->contents->sibur--;
        con->player->inventory->sibur++;
        create_buff(&con->write_buff, "ok\n");
        send_all_gui_take(all, con->player->crds, 3);
        return;
    } if (strcmp(obj, "mendiane\n") == 0 && tile->contents->mendiane > 0) {
        tile->contents->mendiane--;
        con->player->inventory->mendiane++;
        create_buff(&con->write_buff, "ok\n");
        send_all_gui_take(all, con->player->crds, 4);
        return;
    } if (strcmp(obj, "phiras\n") == 0 && tile->contents->phiras > 0) {
        tile->contents->phiras--;
        con->player->inventory->phiras++;
        create_buff(&con->write_buff, "ok\n");
        send_all_gui_take(all, con->player->crds, 5);
        return;
    }
    take3(obj, con, tile, all);
}

void take(char *obj, connection_t *con, game_data_t *data, connection_t *all)
{
    game_tile_t *tile = get_tile(data->map, con->player->crds->x,
        con->player->crds->y);

    if (strcmp(obj, "food\n") == 0 && tile->contents->food > 0) {
        tile->contents->food--;
        con->player->inventory->food += FOOD_TO_LIFE;
        create_buff(&con->write_buff, "ok\n");
        send_all_gui_take(all, con->player->crds, 0);
        return;
    } if (strcmp(obj, "linemate\n") == 0 && tile->contents->linemate > 0) {
        tile->contents->linemate--;
        con->player->inventory->linemate++;
        create_buff(&con->write_buff, "ok\n");
        send_all_gui_take(all, con->player->crds, 1);
        return;
    }
    take2(obj, con, tile, all);
}
