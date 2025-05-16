/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** free_data
*/

#include "my_42sh.h"

//frees the pending commands
void free_commands(data_t *data)
{
    command_t *command_to_free = NULL;

    while (data->command != NULL) {
        my_freestrarray(data->command->command_content);
        my_free(data->command->output_trg);
        my_free(data->command->input_trg_word);
        command_to_free = data->command;
        data->command = data->command->next;
        free(command_to_free);
    }
    data->is_invalid_null_command = false;
    data->is_ambiguous_input_redirect = false;
    data->is_ambiguous_output_redirect = false;
    data->is_missing_redirect_name = false;
    data->command = NULL;
}

static void free_aliases(data_t *data)
{
    alias_t *alias = data->aliases;
    alias_t *alias_to_free = NULL;

    if (alias == NULL)
        return;
    while (alias != NULL) {
        alias_to_free = alias;
        alias = alias->next;
        my_free(alias_to_free->name);
        my_free(alias_to_free->command);
        free(alias_to_free);
    }
}

static void free_history(data_t *data)
{
    history_entry_t *entry = data->history;
    history_entry_t *entry_to_free = NULL;

    if (entry == NULL)
        return;
    while (entry != NULL) {
        entry_to_free = entry;
        entry = entry->next;
        my_free(entry_to_free->command);
        free(entry_to_free);
    }
}

//frees the program data
void free_data(data_t *data)
{
    free_commands(data);
    free_env(data);
    free_aliases(data);
    free_history(data);
}
