/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char const *str)
{
    int len = my_strlen(str) - 1;
    char *buff = NULL;

    if (str == NULL)
        return (NULL);
    buff = malloc(len * sizeof(char));
    if (buff == NULL)
        return (NULL);
    for (int i = 0; i < len + 1; i++) {
        buff[i] = str[len - i];
    }
    return (buff);
}
