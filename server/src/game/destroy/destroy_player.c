/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_player
*/

#include "server.h"
#include <stdlib.h>

void destroy_found_player(player_t *player)
{
    while (player->commands)
        destroy_command(&player->commands);
    free(player->crds);
    free(player->inventory);
    free(player);
}

void remove_player_from_list(player_t *player, player_list_t **list)
{
    player_list_t *tmp = *list;

    if (!tmp)
        return;
    if (tmp->player == player) {
        *list = tmp->next;
        free(tmp);
        return;
    }
    for (player_list_t *curr = tmp; curr && curr->next; curr = curr->next)
        if (curr->next->player == player) {
            tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
            return;
        }
}

void destroy_player(player_t *player, game_data_t *data, connection_t *all)
{
    for (connection_t *curr = all; curr; curr = curr->next)
        if (curr->gui_con)
            send_gui_death(curr, player);
    remove_player_from_list(player, &data->players);
    for (team_t *curr = data->teams; curr; curr = curr->next)
        remove_player_from_list(player, &curr->players);
    destroy_found_player(player);
}
