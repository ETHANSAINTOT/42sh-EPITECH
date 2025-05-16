/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** my_strstr
*/

#include "my.h"

char *my_strstr(char const *str, char const *sub)
{
    int sublen = my_strlen(sub);

    if (str == NULL || sub == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp(str + i, sub, sublen) == 0 &&
            my_strlen(str + i) >= my_strlen(sub)) {
            return ((char *)str + i);
        }
    }
    return (NULL);
}
