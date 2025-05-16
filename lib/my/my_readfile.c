/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** my_readfile
*/

#include "my.h"

char *my_readfile(char const *trg)
{
    FILE *file = fopen(trg, "r");
    char *buff = NULL;
    unsigned int size = 0;

    if (file == NULL)
        return (NULL);
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    buff = malloc(size * sizeof(char) + 1);
    if (buff == NULL) {
        fclose(file);
        return (NULL);
    }
    fread(buff, size, sizeof(char), file);
    buff[size] = '\0';
    fclose(file);
    return (buff);
}
