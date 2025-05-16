/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_segfault
*/

#include "my.h"

void my_segfault(void)
{
    long *boom = (void *)1;

    boom = (long *) *boom;
    return;
}
