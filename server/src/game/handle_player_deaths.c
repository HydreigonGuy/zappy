/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_player_deaths
*/

#include "server.h"

void handle_player_deaths(game_data_t *data, connection_t *connect)
{
    for (player_list_t *curr = data->players; curr; curr = curr->next)
        curr->player->inventory->food--;
    for (connection_t *curr = connect; curr; curr = curr->next)
        if (curr->player && curr->player->inventory->food <= 0) {
            curr->status = DEAD;
            create_buff(&curr->write_buff, "dead\n\0");
        }
}
