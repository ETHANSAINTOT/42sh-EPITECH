/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_free
*/

#include "my.h"

void my_free(void *ptr)
{
    if (ptr != NULL)
        free(ptr);
}
