/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char const *str)
{
    int i = 0;
    int value = 0;
    bool neg = false;

    if (str == NULL) {
        return (0);
    }
    if (str[i] == '-') {
        neg = true;
        i = 1;
    }
    for (; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {
        value = value * 10 + str[i] - 48;
    }
    if (neg == true) {
        return (-value);
    } else {
        return (value);
    }
}
