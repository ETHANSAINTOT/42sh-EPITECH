/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_setbackgroundcol
*/

#include "my.h"

static void print_u_char_as_hex(u_char const n)
{
    char buff[] = "00";

    buff[0] = '0' + n / 16;
    buff[1] = '0' + n % 16;
    if (buff[0] > '9')
        buff[0] += 7;
    if (buff[1] > '9')
        buff[1] += 7;
    my_putstr(buff);
}

//my_printf("\e]11;#%02x%02x%02x\a", r, g, b);
void my_setbackgroundcol(u_char const r, u_char const g, u_char const b)
{
    my_putstr("\033]11;#");
    print_u_char_as_hex(r);
    print_u_char_as_hex(g);
    print_u_char_as_hex(b);
    my_putstr("\a");
}
