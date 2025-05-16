/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_freestrarray
*/

#include "my.h"

void my_freestrarray(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i] != NULL)
            free(arr[i]);
    }
    free(arr);
}
