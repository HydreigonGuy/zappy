/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_args
*/

#include "server.h"
#include <stdio.h>
#include <string.h>

int handle_args(int ac, char **av)
{
    game_data_t *game_data = new_game_data();

    if (!game_data)
        return (malloc_error());
    for (int i = 1; i < ac;) {
        if (strcmp(av[i], "-n") == 0)
            i = add_arg_teams(i + 1, ac, av, game_data);
        if (i + 1 < ac)
            i = add_arg(av, i, game_data);
        if (i == -1 || i + 1 == ac)
            return (arg_error());
    }
    if (!game_data->teams)
        return (missing_teams(game_data));
    if (game_data->port <= 0)
        return (84);
    fill_map_data(game_data->map);
    return (start_server(game_data));
}
