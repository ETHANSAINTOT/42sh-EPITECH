/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_isalphanum
*/

#include "my.h"

int my_isalphanum(char const c)
{
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')) {
        return (1);
    } else {
        return (0);
    }
}
