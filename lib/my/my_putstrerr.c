/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** my_putstrerr
*/

#include "my.h"

void my_putstrerr(char const *str)
{
    int len = my_strlen(str);

    if (str != NULL) {
        write(2, str, len);
    } else {
        my_putstrerr("NULPTRWRN");
    }
}
