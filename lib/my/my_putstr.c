/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** my_putstr
*/

#include "my.h"

void my_putstr(char const *str)
{
    int len = my_strlen(str);

    if (str != NULL) {
        write(1, str, len);
    } else {
        my_putstr("NULPTRWRN");
    }
}
