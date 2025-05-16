/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_do_char_match
*/

#include "my.h"

int my_do_char_match(char a, char b)
{
    if (a == b)
        return (1);
    if (a >= 65 && a <= 90 && a + 32 == b)
        return (1);
    if (b >= 65 && a <= 90 && b + 32 == a)
        return (1);
    return (0);
}
