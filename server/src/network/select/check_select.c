/*
** EPITECH PROJECT, 2022
** server
** File description:
** check_select
*/

#include "server.h"
#include <sys/select.h>

void reset_fds(fd_set *read_fds, fd_set *write_fds, fd_set *ex_fds,
connection_t *connect)
{
    FD_ZERO(read_fds);
    FD_ZERO(write_fds);
    FD_ZERO(ex_fds);
    for (connection_t *curr = connect; curr; curr = curr->next) {
        if (curr->status == READ)
            FD_SET(curr->fd, read_fds);
        if (curr->status == WRITE || curr->status == DEAD)
            FD_SET(curr->fd, write_fds);
        FD_SET(curr->fd, ex_fds);
    }
}

void handle_ready_conncetions(fd_set *r_fds, fd_set *w_fds, fd_set *ex_fds,
connection_t *connect)
{
    for (connection_t *curr = connect; curr; curr = curr->next) {
        if (curr->status == READ && FD_ISSET(curr->fd, r_fds))
            curr->ready = 1;
        if ((curr->status == WRITE || curr->status == DEAD) &&
            FD_ISSET(curr->fd, w_fds))
            curr->ready = 1;
        if (FD_ISSET(curr->fd, ex_fds))
            curr->status = DISCONNECTED;
    }
}

void fill_tv(struct timeval *tv, connection_t *con)
{
    tv->tv_sec = 1;
    tv->tv_usec = 0;
    if (!con) {
        tv->tv_sec = 42;
        tv->tv_usec = 0;
    }
}

void check_select(server_t *server, connection_t *connect)
{
    struct timeval tv;
    fd_set read_fds;
    fd_set write_fds;
    fd_set ex_fds;

    fill_tv(&tv, connect);
    set_all_unready(server, connect);
    reset_fds(&read_fds, &write_fds, &ex_fds, connect);
    FD_SET(server->server_socket, &read_fds);
    FD_SET(0, &read_fds);
    if (select(get_select_num(server->server_socket, connect),
        &read_fds, &write_fds, &ex_fds, &tv) == -1)
        return;
    if (FD_ISSET(server->server_socket, &read_fds))
        server->can_accept = 1;
    if (FD_ISSET(0, &read_fds))
        server->stdin_ready = 1;
    handle_ready_conncetions(&read_fds, &write_fds, &ex_fds, connect);
}
