/*
** EPITECH PROJECT, 2022
** server
** File description:
** check_if_gui_cmd
*/

int check_if_gui_cmd(char *str)
{
    if (str[0] > '9' || str[0] < '0')
        return (0);
    if (str[1] == ' ')
        return (1);
    if (str[1] > '9' || str[1] < '0')
        return (0);
    if (str[2] == ' ')
        return (1);
    if (str[2] > '9' || str[2] < '0')
        return (0);
    if (str[3] == ' ')
        return (1);
    return (0);
}
