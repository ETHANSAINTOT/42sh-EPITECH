/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_readfd
*/

#include "my.h"

char *my_readfd(int const fd)
{
    char *buff = NULL;
    unsigned int size = 0;

    if (fcntl(fd, F_GETFD) == -1)
        return (NULL);
    size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    buff = malloc(size * sizeof(char) + 1);
    if (buff == NULL) {
        return (NULL);
    }
    read(fd, buff, size);
    buff[size] = '\0';
    return (buff);
}
