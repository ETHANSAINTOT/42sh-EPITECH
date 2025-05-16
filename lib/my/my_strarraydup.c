/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strarraydup
*/

#include "my.h"

char **my_strarraydup(char **src)
{
    char **array = NULL;
    int i = 0;

    if (src == NULL)
        return NULL;
    array = malloc(sizeof(char *) * (my_ptrarraylen((void **)src) + 1));
    if (array == NULL)
        return (NULL);
    for (; src[i] != NULL; i++) {
        array[i] = my_strdup(src[i]);
    }
    array[i] = NULL;
    return (array);
}
