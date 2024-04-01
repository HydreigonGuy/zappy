/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_egg_life
*/

#include "server.h"
#include <stddef.h>

void handle_egg_hatching(egg_t *egg, game_data_t *data, team_t *team,
connection_t *all)
{
    if (egg->time >= 600) {
        if (egg->con) {
            egg->con->player = new_player(data);
            egg->con->player->crds = egg->crds;
            insert_new_player(egg->con, data, team);
            send_gui_egg_hatch(all, egg);
        }
        if (!egg->con)
            send_gui_egg_death(all, egg->id);
        destroy_egg(egg, &team->eggs);
    }
}

void handle_egg_life(game_data_t *data, connection_t *all)
{
    egg_t *tmp = NULL;

    for (team_t *team = data->teams; team; team = team->next)
        for (egg_t *egg = team->eggs; egg; egg = tmp) {
            egg->time++;
            tmp = egg->next;
            handle_egg_hatching(egg, data, team, all);
        }
}
