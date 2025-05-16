/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_putstrfallback.c
*/

#include "my.h"

void my_putstrfallback(char const *str, char const *errstr)
{
    if (str != NULL) {
        my_putstr(str);
    } else {
        my_putstr(errstr);
    }
}
