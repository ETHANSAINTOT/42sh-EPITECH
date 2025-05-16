/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_setunderlinecol
*/

#include "my.h"

void my_setunderlinecol(u_char const r, u_char const g, u_char const b)
{
    mini_printf("\033[58;2;%i;%i;%im", r, g, b);
}
