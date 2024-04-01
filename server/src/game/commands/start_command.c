/*
** EPITECH PROJECT, 2022
** server
** File description:
** start_command
*/

#include "server.h"

void start_command(player_t *player)
{
    int time = get_command_enc_time(player->commands->command_str);

    if (time != -1) {
        player->commands->incantation = time;
        player->commands->started = 1;
        return;
    }
    destroy_command(&player->commands);
    if (player->commands)
        start_command(player);
}
