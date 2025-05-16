/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int const n)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (; src[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
