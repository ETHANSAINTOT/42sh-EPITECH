/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_putinterr
*/

#include "my.h"

void my_putinterr(int nb)
{
    int n = nb;
    int l = 1;

    if (n < 0) {
        my_putcharerr('-');
        nb = -nb;
        n = -n;
    }
    while (n > 9) {
        n = n / 10;
        l = l + 1;
    }
    while (l != 0) {
        n = nb;
        for (int j = 0; j < l - 1; j++) {
            n = n / 10;
        }
        l = l - 1;
        my_putcharerr(48 + n % 10);
    }
}
