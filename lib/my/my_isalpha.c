/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_isalpha
*/

#include "my.h"

int my_isalpha(char const c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z')) {
        return (1);
    } else {
        return (0);
    }
}
