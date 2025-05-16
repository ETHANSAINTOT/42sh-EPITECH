/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_writetofile.c
*/

#include "my.h"

void my_writetofile(char const *trg, char const *str)
{
    FILE *file = fopen(trg, "w");

    if (file == NULL)
        return;
    fwrite(str, my_strlen(str), 1, file);
    fclose(file);
}
