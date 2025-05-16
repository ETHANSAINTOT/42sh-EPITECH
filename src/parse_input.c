/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_input
*/

#include "my_42sh.h"

static void get_separator_type(char *str, command_t *command)
{
    command->separator_type = '\0';
    if (str[my_strlen(str) - 1] == ';' ||
        str[my_strlen(str) - 1] == '|') {
        command->separator_type = str[my_strlen(str) - 1];
        str[my_strlen(str) - 1] = ' ';
    }
}

//get the redirect target
static void extract_target(data_t *data, char *str, char **arg, char mode)
{
    int pad_len = my_wordleninv(str, " \t<>");
    int arg_len = my_wordlen(str + pad_len, " \t<>");

    if (*arg == NULL) {
        *arg = my_strndup(str + pad_len, arg_len);
        if (my_strlen(*arg) == 0) {
            data->is_missing_redirect_name = true;
        }
    } else {
        if (mode == '<')
            data->is_ambiguous_input_redirect = true;
        if (mode == '>')
            data->is_ambiguous_output_redirect = true;
    }
    for (int i = 0; i < arg_len; i++) {
        str[pad_len + i] = ' ';
    }
}

//gets target and type of redirect
static void get_redirect(data_t *data, char *str, command_t *command)
{
    if (str[0] == '>') {
        str[0] = ' ';
        if (str[1] == '>') {
            str[1] = ' ';
            command->is_output_append = true;
        }
        extract_target(data, str, &command->output_trg, '>');
        if (command->separator_type == '|')
            data->is_ambiguous_output_redirect = true;
    }
    if (str[0] == '<') {
        str[0] = ' ';
        if (str[1] == '<') {
            str[1] = ' ';
            command->is_input_here = true;
        }
        extract_target(data, str, &command->input_trg_word, '<');
    }
}

//parses the command for redirects
static void handle_redirects(data_t *data, char *str, command_t *command)
{
    command->output_trg = NULL;
    command->input_trg_word = NULL;
    command->is_input_here = false;
    command->is_output_append = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '>' || str[i] == '<') {
            get_redirect(data, str + i, command);
        }
    }
    return;
}

//replace the tile ~ with the HOME path
static void handle_args_tilde(data_t *data, command_t *command)
{
    char *buffer = NULL;
    char *home_path = get_env_value(data, "HOME");

    if (command->args == NULL)
        return;
    for (int i = 0; command->args[i] != NULL; i++) {
        if (home_path != NULL) {
            buffer = my_strreplace(command->args[i],
            "~", home_path);
            my_free(command->args[i]);
            command->args[i] = buffer;
        }
    }
}

static void parse_command(data_t *data, char *str)
{
    char **command_content = NULL;
    command_t *command = NULL;

    command = malloc(sizeof(command_t));
    if (command == NULL)
        exit(84);
    get_separator_type(str, command);
    handle_redirects(data, str, command);
    command_content = my_strsplit(str, " \t", false);
    command->command = command_content[0];
    if (command_content[0] != NULL) {
        command->args = command_content + 1;
    } else {
        command->args = NULL;
    }
    handle_args_tilde(data, command);
    command->command_content = command_content;
    command->next = data->command;
    data->command = command;
}

static void check_invalid_null_command(data_t *data, char *str)
{
    char **arr = my_strsplit(str, " \t", false);

    if (str == NULL || arr == NULL) {
        my_freestrarray(arr);
        data->is_invalid_null_command = true;
        return;
    }
    if (my_ptrarraylen((void **) arr) == 0) {
        my_freestrarray(arr);
        return;
    }
    if (my_strchr("|", arr[0][0]) != NULL ||
        my_strchr("|", arr[my_ptrarraylen((void **) arr) - 1]
        [my_strlen(arr[my_ptrarraylen((void **) arr) - 1]) - 1])
        != NULL) {
        data->is_invalid_null_command = true;
        my_freestrarray(arr);
        return;
    }
    my_freestrarray(arr);
}

static void check_errors(data_t *data)
{
    if (data->is_ambiguous_input_redirect) {
        my_putstr("Ambiguous input redirect.\n");
        free_commands(data);
        data->status = 1;
    }
    if (data->is_ambiguous_output_redirect) {
        my_putstr("Ambiguous output redirect.\n");
        free_commands(data);
        data->status = 1;
    }
    if (data->is_missing_redirect_name) {
        my_putstr("Missing name for redirect.\n");
        free_commands(data);
        data->status = 1;
    }
    if (data->is_invalid_null_command) {
        my_putstr("Invalid null command.\n");
        free_commands(data);
        data->status = 1;
    }
}

void parse_input(data_t *data)
{
    char **commands_list = NULL;

    free_commands(data);
    commands_list = my_strsplit(data->input, ";|", true);
    if (commands_list == NULL)
        return;
    check_invalid_null_command(data, data->input);
    for (int i = my_ptrarraylen((void **) commands_list); i != 0; i--) {
        parse_command(data, commands_list[i - 1]);
        }
    my_free(data->input);
    my_freestrarray(commands_list);
    check_errors(data);
}
