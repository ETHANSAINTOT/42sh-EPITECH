/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** builtin_unalias
*/

#include "my_42sh.h"

static void delete_alias(data_t *data, char *name)
{
    alias_t **alias = &data->aliases;
    alias_t *alias_to_free = NULL;

    while (*alias != NULL) {
        if (my_strcmp((*alias)->name, name) == 0) {
            alias_to_free = *alias;
            *alias = (*alias)->next;
            my_free(alias_to_free->name);
            my_free(alias_to_free->command);
            free(alias_to_free);
            return;
        }
        alias = &(*alias)->next;
    }
}

static void delete_aliases(data_t *data)
{
    for (int i = 0; data->command->args[i] != NULL; i++) {
        delete_alias(data, data->command->args[i]);
    }
}

//checks if alias is called
bool builtin_unalias(data_t *data)
{
    if (my_strcmp(data->command->command, "unalias") == 0) {
        if (my_ptrarraylen((void **) data->command->args) == 0) {
            fprintf(stderr, "unalias: Too few arguments.\n");
            data->status = 1;
        } else {
            delete_aliases(data);
            data->status = 0;
        }
        return (true);
    }
    return (false);
}
