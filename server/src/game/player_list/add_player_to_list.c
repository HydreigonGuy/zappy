/*
** EPITECH PROJECT, 2022
** server
** File description:
** add_player_to_list
*/

#include "server.h"
#include <stdlib.h>

static player_list_t *create_new_player_list(player_t *player)
{
    player_list_t *new = malloc(sizeof(player_list_t));

    if (!new)
        return (NULL);
    new->next = NULL;
    new->player = player;
    return (new);
}

void add_player_to_list(player_t *player, player_list_t **list)
{
    player_list_t *tmp = *list;

    if (!tmp) {
        *list = create_new_player_list(player);
    } else {
        for (; tmp && tmp->next; tmp = tmp->next);
        tmp->next = create_new_player_list(player);
    }
}
