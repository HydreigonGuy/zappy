/*
** EPITECH PROJECT, 2022
** server
** File description:
** new_game_tile
*/

#include "server.h"
#include <stdlib.h>

game_tile_t *new_game_tile(void)
{
    game_tile_t *new = malloc(sizeof(game_tile_t));

    if (!new)
        return (NULL);
    new->contents = new_contents();
    if (!new->contents) {
        free(new);
        return (NULL);
    }
    return (new);
}
