/*
** EPITECH PROJECT, 2022
** server
** File description:
** main
*/

#include "server.h"
#include <time.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac == 2 && handle_help(av[1]))
        return (0);
    return (handle_args(ac, av));
}
