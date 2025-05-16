/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_hidecursor.c
*/

#include "my.h"

void my_hidecursor(void)
{
    my_putstr("\033[?25l");
}
