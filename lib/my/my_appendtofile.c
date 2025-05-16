/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_appendtofile
*/

#include "my.h"

void my_appendtofile(char const *trg, char const *str)
{
    FILE *file = fopen(trg, "a");

    if (file == NULL)
        return;
    fwrite(str, my_strlen(str), 1, file);
    fclose(file);
}
