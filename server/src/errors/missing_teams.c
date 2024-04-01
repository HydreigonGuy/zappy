/*
** EPITECH PROJECT, 2022
** server
** File description:
** missing_teams
*/

#include "server.h"
#include <stdlib.h>
#include <stdio.h>

int missing_teams(game_data_t *data)
{
    free(data->map);
    free(data);
    printf("ERROR: missing team names\n");
    printf("try adding -n Name1 Name2 etc...\n");
    return (84);
}
