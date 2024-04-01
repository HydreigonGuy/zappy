/*
** EPITECH PROJECT, 2022
** client
** File description:
** new_buffer
*/

#include <stdlib.h>
#include "client.h"

buffer_t *new_buffer(void)
{
    buffer_t *buff = malloc(sizeof(buffer_t));

    if (!buff)
        return (NULL);
    buff->buff = NULL;
    buff->next = NULL;
    return (buff);
}
