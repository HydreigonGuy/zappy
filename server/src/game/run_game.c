/*
** EPITECH PROJECT, 2022
** server
** File description:
** run_game
*/

#include "server.h"

void run_game(game_data_t *data, connection_t *connects)
{
    cycle_commands(data, connects);
    handle_elevation_starts(data, connects);
    handle_food_spawn(data->map);
    handle_player_deaths(data, connects);
    handle_egg_life(data, connects);
    handle_win(data);
}
