/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_elvtn_res
*/

#include "server.h"
#include <stdio.h>

void send_gui_elvtn_res(connection_t *con, crds_t *crds, int res)
{
    char resp[60] = {'\0'};

    sprintf(resp, "75 [%i, %i, %i] end of encantation\n\0",
    crds->x, crds->y, res);
    create_buff(&con->write_buff, resp);
}
