/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_countwords
*/

#include "my.h"

int my_countwords(char const *str)
{
    int c = 0;
    char last = '\0';

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalphanum(str[i]) == 1 && my_isalphanum(last) == 0) {
            c++;
        }
        last = str[i];
    }
    return (c);
}
