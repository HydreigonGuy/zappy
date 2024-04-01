/*
** EPITECH PROJECT, 2022
** client
** File description:
** check_select
*/

#include "client.h"
#include <sys/select.h>

void fill_fds(client_t *cli, fd_set *r_fds, fd_set *w_fds, fd_set *e_fds)
{
    FD_ZERO(r_fds);
    FD_ZERO(w_fds);
    FD_ZERO(e_fds);
    cli->ready = 0;
    if (cli->status == READ)
        FD_SET(cli->socket, r_fds);
    if (cli->status == WRITE)
        FD_SET(cli->socket, w_fds);
    FD_SET(cli->socket, e_fds);
}

void fill_tv(struct timeval *tv)
{
    tv->tv_sec = 30;
    tv->tv_usec = 0;
}

void check_select(client_t *client)
{
    struct timeval tv;
    fd_set read_fds;
    fd_set write_fds;
    fd_set ex_fds;

    fill_tv(&tv);
    fill_fds(client, &read_fds, &write_fds, &ex_fds);
    if (select(client->socket + 1,
        &read_fds, &write_fds, &ex_fds, &tv) == -1)
        return;
    if ((client->status == READ && FD_ISSET(client->socket, &read_fds))
        || (client->status == WRITE && FD_ISSET(client->socket, &write_fds)))
        client->ready = 1;
    if (FD_ISSET(client->socket, &ex_fds))
        client->ready = 2;
}
