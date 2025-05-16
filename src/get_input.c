/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** get_input
*/

#include "my_42sh.h"

//gets the string input from either the user(terminal) or the pipe
void get_input(data_t *data)
{
    char *buff = NULL;
    ssize_t size;

    size = getline(&buff, &size, stdin);
    if (size == -1) {
        if (isatty(0) != 0)
            my_putstr("exit\n");
        my_free(buff);
        free_env(data);
        exit(data->status);
    }
    if (buff[my_strlen(buff) - 1] == '\n')
        buff[my_strlen(buff) - 1] = '\0';
    else
        buff[my_strlen(buff)] = '\0';
    if (my_strlen(buff) == 0) {
        free(buff);
        data->input = NULL;
    } else
        data->input = buff;
}
