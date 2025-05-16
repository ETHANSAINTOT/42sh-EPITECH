/*
** EPITECH PROJECT, 2025
** my_lib
** File description:
** my_putchar
*/

#include "my.h"

void my_putchar(char const c)
{
    write(1, &c, 1);
}
