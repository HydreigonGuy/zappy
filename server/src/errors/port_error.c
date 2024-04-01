/*
** EPITECH PROJECT, 2022
** server
** File description:
** port_error
*/

#include "server.h"
#include <stdio.h>

int port_error(game_data_t *data)
{
    destroy_game_data(data);
    printf("ERROR: server could not run on this port, try another one!\n");
    return (84);
}
