/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strcount
*/

#include "my.h"

int my_strcount(char *str, char const *trg)
{
    int c = 0;
    char *ptr = str;

    if (str == NULL || trg == NULL)
        return (0);
    while (my_strstr(ptr, trg) != NULL) {
        c++;
        ptr = my_strstr(ptr, trg) + my_strlen(trg);
    }
    return (c);
}
