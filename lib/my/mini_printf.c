/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** mini_printf
*/

#include "my.h"

static void print_arg(char const type, va_list list, int *c)
{
    int i = 0;
    char *s = NULL;

    if (type == 's') {
        s = va_arg(list, char *);
        my_putstr(s);
        *c = *c + my_strlen(s);
    } else if (type == 'i' || type == 'd') {
        i = va_arg(list, int);
        my_putint(i);
        *c = *c + my_intlen(i);
    }
    if (type == 'c') {
        my_putchar(va_arg(list, int));
        *c = *c + 1;
    } else if (type == '%') {
        *c = *c + 1;
        my_putchar('%');
    }
}

int mini_printf(char const *str, ...)
{
    va_list list;
    int c = 0;

    if (str == NULL) {
        my_putstr("NULPTRWRN");
        return (9);
    }
    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '%') {
            my_putchar(str[i]);
            c++;
        } else {
            print_arg(str[i + 1], list, &c);
            i++;
        }
    }
    va_end(list);
    return (c);
}
