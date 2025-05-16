/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (0);
    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return (s1[i] + s2[i]);
        if (s1[i] < s2[i])
            return (s1[i] - s2[i]);
    }
    if (s1[i] > s2[i])
        return (s1[i] + s2[i]);
    if (s1[i] < s2[i])
        return (s1[i] - s2[i]);
    return (0);
}
