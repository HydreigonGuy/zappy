/*
** EPITECH PROJECT, 2022
** client
** File description:
** create_buff
*/

#include "client.h"
#include <string.h>

void create_buff(buffer_t **buff, const char *str)
{
    buffer_t *tmp = *buff;

    if (!tmp) {
        *buff = new_buffer();
        tmp = *buff;
        if (!tmp)
            return;
        tmp->buff = strdup(str);
    } else {
        for (; tmp && tmp->next; tmp = tmp->next);
        tmp->next = new_buffer();
        if (!tmp->next)
            return;
        tmp->next->buff = strdup(str);
    }
}
