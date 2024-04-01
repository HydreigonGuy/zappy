/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_egg_hatch
*/

#include "server.h"
#include <stdio.h>

void send_gui_egg_hatch(connection_t *all, egg_t *egg)
{
    char resp[130] = {'\0'};

    sprintf(resp, "90 [%s, %s, %s, %s] Player connection\n\0", egg->id,
    egg->con->player->id, egg->crds->x, egg->crds->y);
    for (connection_t *curr = all; curr; curr = curr->next)
        if (curr->gui_con)
            create_buff(&curr->write_buff, resp);
}
