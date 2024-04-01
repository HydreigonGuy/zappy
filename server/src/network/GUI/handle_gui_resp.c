/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_gui_resp
*/

#include "server.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void handle_gui_resp(connection_t *connect, game_data_t *data,
connection_t *all)
{
    char *command = get_command_from_buff(&connect->read_buff);
    int incubating = 0;

    while (command) {
        printf(command);
        if (check_if_team_name(command, data->teams))
            incubating = init_player(connect, command, data, all);
        if (check_if_gui_cmd(command))
            send_gui_info(command, connect, data);
        if (!check_if_gui_cmd(command) && incubating == 0 &&
            !connect->player && connect->status != DEAD) {
            create_buff(&connect->write_buff, "Invalid Team Name\n");
            connect->status = DEAD;
        }
        free(command);
        command = get_command_from_buff(&connect->read_buff);
    }
}
