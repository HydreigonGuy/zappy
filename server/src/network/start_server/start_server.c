/*
** EPITECH PROJECT, 2022
** server
** File description:
** start_server
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>

int start_server(game_data_t *data)
{
    server_t *server = create_server(data->port);

    if (!server || !bind_server(server) || !make_server_listen(server))
        return (port_error(data));
    run_server(server, data);
    close(server->server_socket);
    free(server);
    destroy_game_data(data);
    return (0);
}
