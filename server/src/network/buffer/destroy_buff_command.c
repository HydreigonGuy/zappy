/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_buff_command
*/

#include "server.h"
#include <string.h>

void destroy_buff_command(buffer_t **buff)
{
    buffer_t *tmp = *buff;
    int shift = 0;
    int i = 0;

    while (tmp && find_command_end(tmp->buff) == -1) {
        destroy_buffer(buff);
        tmp = *buff;
    }
    if (!tmp)
        return;
    if (find_command_end(tmp->buff) == strlen(tmp->buff))
        destroy_buffer(buff);
    else {
        shift = find_command_end(tmp->buff);
        for (; tmp->buff[shift + i]; i++)
            tmp->buff[i] = tmp->buff[shift + i];
        tmp->buff[i] = '\0';
    }
}
