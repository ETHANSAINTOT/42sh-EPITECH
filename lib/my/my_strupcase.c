/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strupcase
*/

#include "my.h"

char *my_strupcase(char const *str)
{
    char *buff = NULL;

    if (str == NULL)
        return (NULL);
    buff = my_strdup(str);
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] >= 97 && buff[i] <= 122) {
            buff[i] = buff[i] - 32;
        }
    }
    return (buff);
}
