/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_player_command
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

void handle_player_command(connection_t *connect)
{
    char *command = get_command_from_buff(&connect->read_buff);

    while (command) {
        printf(command);
        if (get_command_len(connect->player->commands) >= 10)
            free(command);
        if (get_command_len(connect->player->commands) < 10)
            create_command(&connect->player->commands, command);
        command = get_command_from_buff(&connect->read_buff);
    }
}
