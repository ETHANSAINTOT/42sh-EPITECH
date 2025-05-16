/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** builtin_env
*/

#include "my_42sh.h"

//checks if env is properly called and display the env variables if so
bool builtin_env(data_t *data)
{
    if (my_strcmp(data->command->command, "env") == 0) {
        if (my_ptrarraylen((void **) data->command->args) != 0) {
            fprintf(stderr, "env: Expression Syntax.\n");
            data->status = 1;
            return (true);
        }
        display_env(data);
        data->status = 0;
        return (true);
    }
    return (false);
}
