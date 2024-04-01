/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_info
*/

#include "server.h"

void send_gui_info(char *cmd, connection_t *con, game_data_t *data)
{
    int code = get_gui_cmd_code(cmd);

    if (code == 1)
        init_gui_connection(con, data);
    if (code == 0)
        con->status = DEAD;
    if (code == 25)
        send_gui_all_tiles(con, data);
    if (code == 250)
        send_gui_player_info(con, data, cmd);
    if (code == 300)
        send_gui_tile_info(con, data->map, cmd);
}
