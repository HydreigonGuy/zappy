/*
** EPITECH PROJECT, 2022
** server
** File description:
** new_player
*/

#include "server.h"
#include <stdlib.h>

player_t *new_player(game_data_t *data)
{
    player_t *new = malloc(sizeof(player_t));

    if (!new)
        return (NULL);
    new->inventory = new_contents();
    new->crds = new_crds(data->map->width, data->map->heigth);
    if (!new->inventory || !new->crds) {
        if (new->inventory)
            free(new->inventory);
        if (new->crds)
            free(new->crds);
        free(new);
        return (NULL);
    }
    new->commands = NULL;
    new->level = 1;
    new->inventory->food = SPAWN_LIFE;
    new->id = create_id();
    return (new);
}
