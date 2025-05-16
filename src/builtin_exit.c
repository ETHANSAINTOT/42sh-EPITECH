/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** builtin_exit
*/

#include "my_42sh.h"

//checks if exit with an arg is called and exits if so
static void builtin_exit_arg(data_t *data)
{
    int exit_status = my_atoi(data->command->args[0]);

    if (my_ptrarraylen((void **) data->command->args) == 1 &&
        ((my_atoi(data->command->args[0]) != 0 &&
        my_strlen(data->command->args[0]) == my_intlen(
        my_atoi(data->command->args[0]))) ||
        my_strcmp(data->command->args[0], "0") == 0)) {
        my_putstr("exit\n");
        close_pipes(data);
        free_data(data);
        exit(exit_status);
    }
}

//checks if exit with no args is called and exits if so
static void builtin_exit_noarg(data_t *data)
{
    if (my_ptrarraylen((void **) data->command->args) == 0) {
        my_putstr("exit\n");
        close_pipes(data);
        free_data(data);
        exit(0);
    }
}

//checks if exit is called
bool builtin_exit(data_t *data)
{
    if (my_strcmp(data->command->command, "exit") == 0) {
        builtin_exit_noarg(data);
        builtin_exit_arg(data);
        fprintf(stderr, "exit: Expression Syntax.\n");
        return (true);
    }
    return (false);
}
