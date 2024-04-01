/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_buffer
*/

#include "server.h"
#include <stdlib.h>

void destroy_buffer(buffer_t **buff)
{
    buffer_t *tmp = *buff;

    if (tmp) {
        *buff = tmp->next;
        free(tmp->buff);
        free(tmp);
    }
}
