/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_wordleninv
*/

#include "my.h"

int my_wordleninv(char const *str, char *const filter)
{
    int len = 0;

    while (my_strchr(filter, str[len]) != NULL && str[len] != '\0') {
        len++;
    }
    return (len);
}
