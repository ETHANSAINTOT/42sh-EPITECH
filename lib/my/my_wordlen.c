/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_wordlen
*/

#include "my.h"

int my_wordlen(char const *str, char *const filter)
{
    int len = 0;

    while (my_strchr(filter, str[len]) == NULL && str[len] != '\0') {
        len++;
    }
    return (len);
}
