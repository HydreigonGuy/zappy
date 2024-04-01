/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_gui_teams_list
*/

#include "server.h"
#include <stdlib.h>
#include <string.h>

void fill_gui_teams_list_resp(char *resp, team_t *teams)
{
    for (team_t *curr = teams; curr; curr = curr->next) {
        strcat(resp, curr->name);
        if (curr->next)
            strcat(resp, " ");
    }
}

void send_gui_teams_list(connection_t *con, team_t *teams)
{
    int len = 40;
    char *resp = NULL;

    for (team_t *curr = teams; curr; curr = curr->next)
        len += strlen(curr->name) + 1;
    resp = malloc(sizeof(char) * len);
    if (!resp)
        return;
    memset(resp, '\0', len);
    strcat(resp, "20 [");
    fill_gui_teams_list_resp(resp, teams);
    strcat(resp, "] List of team names\n");
    create_buff(&con->write_buff, resp);
    free(resp);
}
