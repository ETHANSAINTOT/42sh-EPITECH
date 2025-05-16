/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strpbrk
*/

#include "my.h"

char *my_strpbrk(char *str, char const *chars)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strchr((char *) chars, str[i]) != NULL) {
            return (str + i);
        }
    }
    return (NULL);
}
