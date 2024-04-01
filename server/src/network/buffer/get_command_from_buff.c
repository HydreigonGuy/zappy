/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_command_from_buff
*/

#include "server.h"
#include <string.h>
#include <stdlib.h>

int find_command_end(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            return (i + 1);
    return (-1);
}

int get_cmd_len(buffer_t *buff)
{
    int len = -1;
    int i = 0;

    for (buffer_t *curr = buff; curr && len == -1; curr = curr->next) {
        len = find_command_end(curr->buff);
        if (len != -1)
            len += i;
        i += strlen(curr->buff);
    }
    return (len);
}

void fill_command_buff_ret(char *ret, char *buff, int c)
{
    int i = 0;

    for (; buff[i] && buff[i] != '\n'; i++, c++)
        ret[c] = buff[i];
    if (buff[i] == '\n') {
        ret[c] = '\n';
        ret[c + 1] = '\0';
    }
}

char *get_command_from_buff(buffer_t **buff)
{
    int len = get_cmd_len(*buff);
    int i = 0;
    char *ret = NULL;

    if (len == -1)
        return (NULL);
    ret = malloc(sizeof(char) * (len + 1));
    if (!ret)
        return (NULL);
    for (buffer_t *curr = *buff; curr && i < len; curr = curr->next) {
        fill_command_buff_ret(ret, curr->buff, i);
        i += strlen(curr->buff);
    }
    destroy_buff_command(buff);
    return (ret);
}
