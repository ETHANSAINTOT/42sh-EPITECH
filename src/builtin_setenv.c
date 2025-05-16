/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** builtin_setenv
*/

#include "my_42sh.h"

//handles all possible setenv uses
static bool handle_setenv_uses(data_t *data)
{
    if (my_ptrarraylen((void **) data->command->args) == 0) {
        display_env(data);
        return (true);
    }
    if (my_ptrarraylen((void **) data->command->args) == 1) {
        set_env_pair(data, data->command->args[0], "");
        return (true);
    }
    if (my_ptrarraylen((void **) data->command->args) == 2) {
        set_env_pair(data, data->command->args[0],
        data->command->args[1]);
        return (true);
    }
    return (false);
}

//return true if the string is only comprised of alphanumeric characters,
//false if not
static bool is_stralphanumonly(char *str)
{
    for (int i = 1; str[i] != '\0'; i++) {
        if (my_isalphanum(str[i]) != 1 && str[i] != '.') {
            return (false);
        }
    }
    return (true);
}

//checks if setenv is properly called
static bool handle_setenv_errors(data_t *data)
{
    if (my_ptrarraylen((void **) data->command->args) >= 1 &&
        my_isalpha(data->command->args[0][0]) == 0 &&
        data->command->args[0][0] != '_') {
        fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
        data->status = 1;
        return (true);
    }
    if (my_ptrarraylen((void **) data->command->args) >= 1 &&
        is_stralphanumonly(data->command->args[0]) == false) {
        fprintf(stderr,
            "setenv: Variable name must contain alphanumeric characters.\n");
        data->status = 1;
        return (true);
    }
    if (my_ptrarraylen((void **) data->command->args) > 2) {
        fprintf(stderr, "setenv: Too many arguments.\n");
        data->status = 1;
        return (true);
    }
    return (false);
}

//checks if setenv is called
bool builtin_setenv(data_t *data)
{
    if (my_strcmp(data->command->command, "setenv") == 0) {
        data->status = 0;
        if (handle_setenv_errors(data) == true)
            return (true);
        if (handle_setenv_uses(data) == true)
            return (true);
        fprintf(stderr, "env: Expression Syntax.\n");
        data->status = 1;
        return (true);
    }
    return (false);
}
