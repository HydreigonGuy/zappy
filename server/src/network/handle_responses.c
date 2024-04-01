/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_responses
*/

#include "server.h"

void handle_responses(connection_t *connect, game_data_t *data)
{
    for (connection_t *curr = connect; curr; curr = curr->next) {
        if (!curr->player)
            handle_gui_resp(curr, data, connect);
        else
            handle_player_command(curr);
    }
}
