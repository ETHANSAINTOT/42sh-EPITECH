/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strreplace
*/

#include "my.h"

static void copy_and_replace(char *buffer, char *str, char const *trg,
    char const *sub)
{
    int bi = 0;
    int si = 0;

    while (str[si] != '\0') {
        if (my_strstr(str + si, trg) == str + si) {
            my_strcpy(buffer + bi, sub);
            bi += my_strlen(sub);
            si += my_strlen(trg);
        } else {
            buffer[bi] = str[si];
            bi++;
            si++;
        }
    }
    buffer[bi] = '\0';
}

char *my_strreplace(char *str, char const *trg, char const *sub)
{
    char *buffer = NULL;
    int trg_number = my_strcount(str, trg);

    if (str == NULL)
        return (NULL);
    if (trg == NULL || sub == NULL)
        return (my_strdup(str));
    buffer = malloc(sizeof(char) *
    (my_strlen(str) + (my_strlen(sub) - my_strlen(trg)) * trg_number + 1));
    if (buffer == NULL)
        return (NULL);
    copy_and_replace(buffer, str, trg, sub);
    return (buffer);
}
