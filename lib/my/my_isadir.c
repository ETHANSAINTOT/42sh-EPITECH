/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_isadir
*/

#include "my.h"

bool my_isadir(char const *file_path)
{
    struct stat file_stats;

    stat(file_path, &file_stats);
    if (S_ISDIR(file_stats.st_mode)) {
        return (true);
    } else {
        return (false);
    }
}
