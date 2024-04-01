/*
** EPITECH PROJECT, 2022
** server
** File description:
** add_arg_teams
*/

#include "server.h"

int add_arg_teams(int i, int max, char **av, game_data_t *game_data)
{
    for (; i < max && check_arg_meaning(av[i]) == -1; i++)
        add_team(&game_data->teams, av[i]);
    return (i);
}
