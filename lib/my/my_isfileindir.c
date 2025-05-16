/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_isfileindir
*/

#include "my.h"

bool my_isfileindir(char const *filename, char const *dirname)
{
    DIR *dir = opendir(dirname);
    struct dirent *file = NULL;

    if (dir == NULL)
        return (false);
    file = readdir(dir);
    while (file != NULL) {
        if (my_strcmp(filename, file->d_name) == 0) {
            closedir(dir);
            return (true);
        }
        file = readdir(dir);
    }
    closedir(dir);
    return (false);
}
