/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** save_history_entry
*/

#include "my_42sh.h"

static void create_new_entry(data_t *data, history_entry_t **pointer_location)
{
    *pointer_location = malloc(sizeof(history_entry_t));
    if (*pointer_location == NULL)
        return;
    data->history_lenght++;
    (*pointer_location)->index = data->history_lenght;
    (*pointer_location)->command = my_strdup(data->input);
    (*pointer_location)->time_stamp = time(NULL);
    (*pointer_location)->next = NULL;
}

void save_history_entry(data_t *data)
{
    history_entry_t *entry = data->history;

    if (data->input == NULL)
        return;
    if (entry == NULL) {
        create_new_entry(data, &data->history);
        return;
    }
    while (entry->next != NULL) {
        entry = entry->next;
    }
    create_new_entry(data, &entry->next);
}
