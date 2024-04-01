/*
** EPITECH PROJECT, 2022
** server
** File description:
** run_server
*/

#include "server.h"
#include <stddef.h>
#include <stdlib.h>

void run_server(server_t *server, game_data_t *data)
{
    connection_t *connect = NULL;
    int runs  = 0;

    gettimeofday(&data->time_stamp, 0);
    while (1) {
        runs = get_number_of_runs(data);
        for (; runs > 0; runs--) {
            set_status(connect);
            check_select(server, connect);
            handle_accept(server, &connect);
            send_response(connect);
            read_message(connect);
            handle_responses(connect, data);
            handle_connection_ends(&connect, data);
            run_game(data, connect);
        }
    }
    destroy_connections(&connect, data);
}
