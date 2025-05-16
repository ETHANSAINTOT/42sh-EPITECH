/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_putstrurl
*/

#include "my.h"

void my_putstrurl(char const *str, char const *url)
{
    if (url != NULL) {
        mini_printf("\033]8;;%s\a", url);
    } else {
        mini_printf("\033]8;;NULPTRWRN\a", url);
    }
    if (str != NULL) {
        my_putstr(str);
    } else {
        my_putstr("NULPTRWRN");
    }
    my_putstr("\033]8;;\a");
}
