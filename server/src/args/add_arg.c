/*
** EPITECH PROJECT, 2022
** server
** File description:
** add_arg
*/

#include "server.h"
#include <stdlib.h>

int add_arg(char **av, int i, game_data_t *game_data)
{
    int meaning = check_arg_meaning(av[i]);

    if (meaning == -1 || atoi(av[i + 1]) == 0)
        return (-1);
    if (meaning == 1)
        game_data->port = atoi(av[i + 1]);
    if (meaning == 2)
        game_data->map->width = atoi(av[i + 1]);
    if (meaning == 3)
        game_data->map->heigth = atoi(av[i + 1]);
    if (meaning == 4)
        game_data->client_num = atoi(av[i + 1]);
    if (meaning == 5)
        game_data->frequency = atoi(av[i + 1]);
    return (i + 2);
}
