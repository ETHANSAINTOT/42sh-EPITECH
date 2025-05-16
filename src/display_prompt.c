/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** display_prompt
*/

#include "my_42sh.h"

static void display_prompt_cwd(data_t *data)
{
    char *cwd = my_strreplace(get_env_value(data, "PWD"),
        get_env_value(data, "HOME"), "~");
    int len = my_strlen(cwd);
    int r = 0;
    int g = 50;
    int b = 255;

    if (cwd == NULL)
        return;
    if (len <= 10)
        len = 10;
    mini_printf("%s", COL_BOLD);
    for (int i = 0; cwd[i] != '\0'; i++) {
        r = (int) ((float) i / len * 255);
        b = 255 - (int) ((float) i / len * 255);
        my_settextcol(r, g, b);
        my_putchar(cwd[i]);
    }
    free(cwd);
}

static void display_prompt_arrow(data_t *data)
{
    if (data->status == 0) {
        my_settextcol(255, 255, 255);
    } else {
        mini_printf("\033[38;5;%im", data->status);
    }
    my_putstr(" > ");
}

static void display_prompt_status(data_t *data)
{
    my_putstr("\033[1000C");
    if (my_intlen(data->status) != 1)
        mini_printf("\033[%iD", my_intlen(data->status) - 1);
    my_putint(data->status);
    my_putstr("\033[1000D");
}

void display_prompt(data_t *data)
{
    display_prompt_status(data);
    display_prompt_cwd(data);
    display_prompt_arrow(data);
    my_putstr(COL_RESET);
}
