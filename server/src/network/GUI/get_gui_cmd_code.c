/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_gui_cmd_code
*/

int get_gui_cmd_code(char *str)
{
    int ret = 0;

    for (int i = 0; str[i] <= '9' && str[i] >= '0'; i++)
        ret = ret * 10 + str[i] - '0';
    return (ret);
}
