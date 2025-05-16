/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strndup
*/

#include "my.h"

char *my_strndup(char const *src, int const n)
{
    int len = my_strlen(src);
    char *cpy = NULL;

    if (src == NULL)
        return (NULL);
    if (len > n)
        len = n;
    cpy = malloc(len * sizeof(char) + 1);
    if (cpy == NULL)
        return (NULL);
    for (int i = 0; src[i] != '\0' && i < n; i++) {
        cpy[i] = src[i];
    }
    cpy[len] = '\0';
    return (cpy);
}
