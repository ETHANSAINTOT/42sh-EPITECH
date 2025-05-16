/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_putcharerr
*/

#include "my.h"

void my_putcharerr(char const c)
{
    write(2, &c, 1);
}
