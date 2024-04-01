/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_number_of_runs
*/

#include "server.h"
#include <stddef.h>

int get_number_of_runs(game_data_t *data)
{
    struct timeval new;
    int diff = 0;
    int ret = 0;

    gettimeofday(&new, 0);
    diff = (new.tv_usec + new.tv_sec * 1000000) -
    (data->time_stamp.tv_usec + data->time_stamp.tv_sec * 1000000);
    while ((diff * data->frequency) / 1000000) {
        ret++;
        diff = 1000000 / (diff * data->frequency);
    }
    if (ret)
        data->time_stamp = new;
    return (ret);
}
