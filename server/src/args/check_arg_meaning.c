/*
** EPITECH PROJECT, 2022
** server
** File description:
** check_arg_meaning
*/

#include <string.h>

int check_arg_meaning(char *str)
{
    if (strcmp(str, "-p") == 0)
        return (1);
    if (strcmp(str, "-x") == 0)
        return (2);
    if (strcmp(str, "-y") == 0)
        return (3);
    if (strcmp(str, "-c") == 0)
        return (4);
    if (strcmp(str, "-f") == 0)
        return (5);
    return (-1);
}
