/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_egg_death
*/

#include "server.h"
#include <stdio.h>

void send_gui_egg_death(connection_t *all, char *id)
{
    char resp[70] = {'\0'};

    sprintf(resp, "110 [%s] egg died\n\0", id);
    for (connection_t *curr = all; curr; curr = curr->next)
        if (curr->gui_con)
            create_buff(&curr->write_buff, resp);
}
