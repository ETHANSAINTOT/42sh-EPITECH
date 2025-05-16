/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_movecursor
*/

#include "my.h"

//x is horizon, y is vertical
void my_movecursor(u_int const x, u_int const y)
{
    mini_printf("\033[%i;%iH", y, x);
}
