/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_help
*/

#include <string.h>
#include <stdio.h>

int handle_help(char *arg)
{
    if (strcmp(arg, "-help") != 0)
        return (0);
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2");
    printf(" ... -c clientsNb -f freq\n");
    printf("\tport\tis the port number\n");
    printf("\twidth\tis the width of the world\n");
    printf("\theight\tis the height of the world\n");
    printf("\tnameX\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\tis the reciprocal of time unit for execution of ");
    printf("actions\n");
    return (1);
}