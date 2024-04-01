/*
** EPITECH PROJECT, 2022
** server
** File description:
** new_game_data
*/

#include "server.h"
#include <stdlib.h>

game_data_t *new_game_data(void)
{
    game_data_t *new = malloc(sizeof(game_data_t));

    if (!new)
        return (NULL);
    new->map = new_map();
    if (!new->map) {
        free(new);
        return (NULL);
    }
    new->frequency = DEFAULT_FREQUENCY;
    new->players = NULL;
    new->teams = NULL;
    new->client_num = DEFAULT_CLIENT_NUM;
    new->port = -1;
    return (new);
}
