/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strchr
*/

#include "my.h"

char *my_strchr(char *str, char const c)
{
    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return (str + i);
        }
    }
    return (NULL);
}
