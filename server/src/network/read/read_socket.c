/*
** EPITECH PROJECT, 2022
** server
** File description:
** read_socket
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>

int read_socket(int fd, buffer_t **buff)
{
    char *r_buff = malloc(sizeof(char) * (READ_SIZE + 1));

    for (int i = 0; i < READ_SIZE + 1; i++)
        r_buff[i] = '\0';
    if (read(fd, r_buff, READ_SIZE) == 0)
        return (0);
    create_buff(buff, r_buff);
    free(r_buff);
    return (1);
}
