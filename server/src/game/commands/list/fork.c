/*
** EPITECH PROJECT, 2022
** server
** File description:
** fork
*/

#include "server.h"

void myfork(connection_t *con, game_data_t *data, connection_t *all)
{
    team_t *team = get_player_team(data->teams, con->player);
    egg_t *egg = create_egg(&team->eggs, con->player->crds);

    create_buff(&con->write_buff, "ok\n");
    for (connection_t *curr = all; curr; curr = curr->next)
        if (curr->gui_con)
            send_gui_egg_laying(curr, con->player, egg);
}
