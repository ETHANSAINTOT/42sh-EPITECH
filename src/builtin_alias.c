/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** builtin_alias
*/

#include "my_42sh.h"

static void print_alias(alias_t *alias)
{
    if (my_strpbrk(alias->command, " \t") != NULL) {
        mini_printf("%s\t(%s)\n", alias->name, alias->command);
    } else {
        mini_printf("%s\t%s\n", alias->name, alias->command);
    }
}

static void display_aliases(data_t *data)
{
    alias_t *alias = data->aliases;

    while (alias != NULL) {
        print_alias(alias);
        alias = alias->next;
    }
}

static void display_alias(data_t *data, char *name)
{
    alias_t *alias = data->aliases;

    while (alias != NULL) {
        if (my_strcmp(alias->name, name) == 0) {
            print_alias(alias);
            return;
        }
        alias = alias->next;
    }
}

static char *dup_command_args(char **args)
{
    int len = 0;
    char *str = NULL;
    int index = 0;

    for (int i = 0; args[i] != NULL; i++)
        len += my_strlen(args[i]) + 1;
    str = malloc(sizeof(char) * len);
    if (str == NULL)
        return NULL;
    for (int i = 0; args[i] != NULL; i++) {
        my_strcpy(str + index, args[i]);
        index += my_strlen(args[i]);
        str[index] = ' ';
        index += 1;
    }
    str[index - 1] = '\0';
    return str;
}

static void create_new_alias(data_t *data, alias_t **pointer_location)
{
    *pointer_location = malloc(sizeof(alias_t));
    if (*pointer_location == NULL)
        return;
    data->history_lenght++;
    (*pointer_location)->name = my_strdup(data->command->args[0]);
    (*pointer_location)->command = dup_command_args(data->command->args + 1);
    (*pointer_location)->next = NULL;
}

static void modify_alias_command(data_t *data, alias_t *alias)
{
    my_free(alias->command);
    alias->command = dup_command_args(data->command->args + 1);
}

static void create_alias(data_t *data)
{
    alias_t *alias = data->aliases;

    if (alias == NULL) {
        create_new_alias(data, &data->aliases);
        return;
    }
    while (alias->next != NULL) {
        if (my_strcmp(alias->name, data->command->args[0]) == 0) {
            modify_alias_command(data, alias);
            return;
        }
        alias = alias->next;
    }
    if (my_strcmp(alias->name, data->command->args[0]) == 0) {
        modify_alias_command(data, alias);
        return;
    }
    create_new_alias(data, &alias->next);
}

//checks if alias is called
bool builtin_alias(data_t *data)
{
    if (my_strcmp(data->command->command, "alias") == 0) {
        if (my_ptrarraylen((void **) data->command->args) == 0)
            display_aliases(data);
        if (my_ptrarraylen((void **) data->command->args) == 1)
            display_alias(data, data->command->args[0]);
        if (my_ptrarraylen((void **) data->command->args) >= 2)
            create_alias(data);
        data->status = 0;
        return (true);
    }
    return (false);
}
