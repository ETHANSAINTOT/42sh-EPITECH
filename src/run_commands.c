/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** run_commands
*/

#include "my_42sh.h"

//checks if the command is a builtin
static void run_builtins(data_t *data)
{
    if (builtin_cd(data) == true)
        return;
    if (builtin_setenv(data) == true)
        return;
    if (builtin_unsetenv(data) == true)
        return;
    if (builtin_env(data) == true)
        return;
    if (builtin_exit(data) == true)
        return;
    if (builtin_history(data) == true)
        return;
    if (builtin_alias(data) == true)
        return;
    if (builtin_unalias(data) == true)
        return;
    if (builtin_which(data) == true)
        return;
}

static bool check_builtins(data_t *data)
{
    for (int i = 0; builtin_names[i] != NULL; i++) {
        if (strcmp(data->command->command, builtin_names[i]) == 0) {
            open_pipes(data);
            run_builtins(data);
            close_pipes(data);
            return (true);
        }
    }
    return (false);
}

//run all queued commands
void run_commands(data_t *data)
{
    command_t *command_to_free = NULL;

    while (data->command != NULL) {
        if (isatty(0) == 0 && data->status != 0) {
            free_data(data);
            exit(data->status);
        }
        if (data->command->command != NULL &&
            check_builtins(data) == false) {
            exec_program(data);
        }
        my_freestrarray(data->command->command_content);
        my_free(data->command->output_trg);
        my_free(data->command->input_trg_word);
        command_to_free = data->command;
        data->command = data->command->next;
        free(command_to_free);
    }
}
