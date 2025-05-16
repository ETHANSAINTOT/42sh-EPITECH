/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** builtin_unsetenv
*/

#include "my_42sh.h"

//checks if unsetenv is properly called and unset the specified
//env variable if so
bool builtin_unsetenv(data_t *data)
{
    if (my_strcmp(data->command->command, "unsetenv") == 0) {
        if (my_ptrarraylen((void **) data->command->args) == 0) {
            fprintf(stderr, "unsetenv: Too few arguments.\n");
            data->status = 1;
            return (true);
        }
        for (int i = 0; data->command->args[i] != NULL; i++) {
            delete_env_pair(data, data->command->args[i]);
            data->status = 0;
        }
        return (true);
    }
    return (false);
}
