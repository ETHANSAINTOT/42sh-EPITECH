/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** builtin_history
*/

#include "my_42sh.h"

static void display_history(data_t *data, int len)
{
    history_entry_t *entry = data->history;
    char time_buffer_string[6] = "";

    for (int i = data->history_lenght - len; entry != NULL && i > 0; i--)
        entry = entry->next;
    while (entry != NULL) {
        strftime(time_buffer_string, 6, "%R", localtime(&entry->time_stamp));
        printf(" % 5i\t%s\t%s\n", entry->index,
            time_buffer_string, entry->command);
        entry = entry->next;
    }
}

//checks if exit is called
bool builtin_history(data_t *data)
{
    int len = 0;

    if (my_strcmp(data->command->command, "history") == 0) {
        if (my_ptrarraylen((void **) data->command->args) >= 1) {
            len = my_atoi(data->command->args[0]);
        } else {
            len = 1000;
        }
        if (len == 0) {
            fprintf(stderr, "history: Badly formed number.\n");
            data->status = 1;
        } else {
            display_history(data, len);
            data->status = 0;
        }
        return (true);
    }
    return (false);
}
