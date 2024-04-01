/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_tile_info
*/

#include "server.h"
#include <stdio.h>

int get_guiti_x(char *str)
{
    int ret = 0;
    int i = 0;

    for (; str[i] && str[i] != '['; i++);
    for (; str[i] && (str[i] < '0' || str[i] > '9'); i++);
    for (; str[i] && str[i] <= '9' && str[i] >= '0'; i++)
        ret = ret * 10 + str[i] - '0';
    return (ret);
}

int get_guiti_y(char *str)
{
    int ret = 0;
    int i = 0;

    for (; str[i] && str[i] != ','; i++);
    for (; str[i] && (str[i] < '0' || str[i] > '9'); i++);
    for (; str[i] && str[i] <= '9' && str[i] >= '0'; i++)
        ret = ret * 10 + str[i] - '0';
    return (ret);
}

void send_gui_tile_info(connection_t *con, map_t *map, char *cmd)
{
    int x = get_guiti_x(cmd);
    int y = get_guiti_y(cmd);
    char resp[80] = {'\0'};
    game_tile_t *tile = get_tile(map, x, y);

    sprintf(resp, "301 [%i, %i, %i, %i, %i, %i, %i] sending tile info\n\0",
    tile->contents->food, tile->contents->linemate, tile->contents->deraumere,
    tile->contents->sibur, tile->contents->mendiane, tile->contents->phiras,
    tile->contents->thystame);
    create_buff(&con->write_buff, resp);
}
