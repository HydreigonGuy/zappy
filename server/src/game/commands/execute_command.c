/*
** EPITECH PROJECT, 2022
** server
** File description:
** execute_command
*/

#include "server.h"
#include <string.h>

void execute_command2(char *str, game_data_t *data, connection_t *con,
connection_t *connections)
{
    if (strncmp(str, "Take ", 5) == 0)
        take(&str[5], con, data, connections);
    if (strncmp(str, "Set ", 4) == 0)
        set(&str[4], con, data, connections);
    if (strcmp(str, "Incantation\n") == 0)
        incantation(con, data, connections);
    if (strcmp(str, "Fork\n") == 0)
        myfork(con, data, connections);
    if (strncmp(str, "Broadcast ", 10) == 0)
        broadcast(&str[10], con, connections, data->map);
}

void execute_command(char *str, game_data_t *data, connection_t *con,
connection_t *connections)
{
    if (strcmp(str, "Forward\n") == 0)
        forward(con->player, con, data->map, connections);
    if (strcmp(str, "Right\n") == 0)
        right(con->player, con, connections);
    if (strcmp(str, "Left\n") == 0)
        left(con->player, con, connections);
    if (strcmp(str, "Inventory\n") == 0)
        inventory(con->player, con);
    if (strcmp(str, "Look\n") == 0)
        look(con->player, con, data);
    if (strcmp(str, "Connect_nbr\n") == 0)
        connect_nbr(con, data);
    if (strcmp(str, "Eject\n") == 0)
        eject(con, data, connections);
    execute_command2(str, data, con, connections);
}
