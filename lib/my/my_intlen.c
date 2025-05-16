/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** my_intlen
*/

int my_intlen(int const nb)
{
    int l = 1;
    int n = nb;

    if (n < 0) {
        n = -n;
        l++;
    }
    while (n > 9) {
        l++;
        n = n / 10;
    }
    return (l);
}
