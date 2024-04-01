/*
** EPITECH PROJECT, 2022
** server
** File description:
** cycle_commands
*/

#include "server.h"

void cycle_player_cmds(game_data_t *data, connection_t *con,
connection_t *connections)
{
    if (!con->player->commands)
        return;
    if (!con->player->commands->started)
        start_command(con->player);
    if (!con->player->commands)
        return;
    if (con->player->commands->started &&
    con->player->commands->incantation <= 0) {
        execute_command(con->player->commands->command_str, data, con,
        connections);
        destroy_command(&con->player->commands);
    }
    if (con->player->commands && con->player->commands->started)
        con->player->commands->incantation--;
}

void cycle_commands(game_data_t *data, connection_t *con)
{
    for (connection_t *curr = con; curr; curr = curr->next)
        if (curr->player)
            cycle_player_cmds(data, curr, con);
}
