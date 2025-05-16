/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** my_strlowercase
*/

#include "my.h"

char *my_strlowercase(char const *str)
{
    char *buff = NULL;

    if (str == NULL)
        return (NULL);
    buff = my_strdup(str);
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] >= 65 && buff[i] <= 90) {
            buff[i] = buff[i] + 32;
        }
    }
    return (buff);
}
