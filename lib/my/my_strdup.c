/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *cpy = NULL;

    if (src == NULL)
        return (NULL);
    cpy = malloc(len * sizeof(char) + 1);
    if (cpy == NULL)
        return (NULL);
    for (int i = 0; src[i] != '\0'; i++) {
        cpy[i] = src[i];
    }
    cpy[len] = '\0';
    return (cpy);
}
