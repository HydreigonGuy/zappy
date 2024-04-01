/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_all_gui_set
*/

#include "server.h"
#include <stdio.h>

void send_all_gui_set(connection_t *all, crds_t *crds, int item)
{
    char resp[50] = {'\0'};

    sprintf(resp, "215 [%i, %i, %i] resource dropped\n\0",
    crds->x, crds->y, item);
    for (connection_t *curr = all; curr; curr = curr->next)
        if (curr->gui_con)
            create_buff(&curr->write_buff, resp);
}
