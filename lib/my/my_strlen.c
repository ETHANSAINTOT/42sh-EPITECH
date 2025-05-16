/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int len = 0;

    if (str == NULL)
        return (-1);
    while (str[len] != 0) {
        len = len + 1;
    }
    return (len);
}
