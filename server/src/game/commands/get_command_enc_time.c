/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_command_enc_time
*/

#include "string.h"

int check_if_str_is_cmp(char *str)
{
    if (strcmp(str, "food\n") == 0)
        return (1);
    if (strcmp(str, "linemate\n") == 0)
        return (1);
    if (strcmp(str, "deraumere\n") == 0)
        return (1);
    if (strcmp(str, "sibur\n") == 0)
        return (1);
    if (strcmp(str, "mendiane\n") == 0)
        return (1);
    if (strcmp(str, "phiras\n") == 0)
        return (1);
    if (strcmp(str, "thystame\n") == 0)
        return (1);
    return (0);
}

int get_command_enc_time2(char *str)
{
    if (strncmp(str, "Broadcast ", 10) == 0)
        return (7);
    if (strncmp(str, "Take ", 5) == 0 && check_if_str_is_cmp(&str[5]))
        return (7);
    if (strncmp(str, "Set ", 4) == 0 && check_if_str_is_cmp(&str[4]))
        return (7);
    return (-1);
}

int get_command_enc_time(char *str)
{
    if (strcmp(str, "Forward\n") == 0)
        return (7);
    if (strcmp(str, "Right\n") == 0)
        return (7);
    if (strcmp(str, "Left\n") == 0)
        return (7);
    if (strcmp(str, "Look\n") == 0)
        return (7);
    if (strcmp(str, "Inventory\n") == 0)
        return (1);
    if (strcmp(str, "Connect_nbr\n") == 0)
        return (0);
    if (strcmp(str, "Fork\n") == 0)
        return (42);
    if (strcmp(str, "Eject\n") == 0)
        return (7);
    if (strcmp(str, "Incantation\n") == 0)
        return (300);
    return (get_command_enc_time2(str));
}
