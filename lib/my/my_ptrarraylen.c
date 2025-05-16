/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_ptrarraylen
*/

#include "my.h"

int my_ptrarraylen(void **array)
{
    int i = 0;

    if (array == NULL)
        return (0);
    for (; array[i]; i++) {
    }
    return (i);
}
