/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** my_putfloat
*/

#include "my.h"

void my_putfloat(float const nb, int const acc)
{
    float n = 0;

    my_putint(nb);
    if (nb > 0) {
        n = nb;
    } else {
        n = - nb;
    }
    if (acc >= 1) {
        my_putchar('.');
        for (int i = 0; i < acc; i++) {
            n = (n - (int)n) * 10;
            my_putint(n);
        }
    }
}
