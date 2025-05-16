/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** main_loop
*/

#include "my_42sh.h"

//looop
void main_loop(data_t *data)
{
    while (true) {
        if (isatty(0) != 0) {
            display_prompt(data);
        }
        get_input(data);
        save_history_entry(data);
        parse_input(data);
        run_commands(data);
    }
}
