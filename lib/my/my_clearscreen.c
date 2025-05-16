/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_clearscreen
*/

#include "my.h"

void my_clearscreen(void)
{
    my_putstr("\033[2J");
}
