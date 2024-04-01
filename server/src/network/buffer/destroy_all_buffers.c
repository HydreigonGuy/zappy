/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_all_buffers
*/

#include "server.h"

void destroy_all_buffers(buffer_t *buff)
{
    while (buff)
        destroy_buffer(&buff);
}
