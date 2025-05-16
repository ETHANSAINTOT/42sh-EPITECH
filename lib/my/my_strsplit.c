/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strsplit
*/

#include "my.h"

static int countwords(char const *str, char *const filter)
{
    int c = 0;
    char last = '\0';

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strchr(filter, str[i]) == NULL &&
            (my_strchr(filter, last) != NULL ||
            last == '\0')) {
            c++;
        }
        last = str[i];
    }
    return (c);
}

static void read_words(char **array, char const *str, char *const filter,
    bool const keep_separator)
{
    int c = 0;
    int word_len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strchr(filter, str[i]) == NULL) {
            word_len = my_wordlen(str + i, filter);
            array[c] = my_strndup(str + i, word_len + (int) keep_separator);
            i += word_len - 1;
            c++;
        }
    }
}

char **my_strsplit(char const *str, char *const filter,
    bool const keep_separator)
{
    int len = countwords(str, filter);
    char **array = NULL;

    if (str == NULL)
        return (NULL);
    array = malloc((len + 1) * sizeof(char *));
    if (array == NULL)
        return (NULL);
    read_words(array, str, filter, keep_separator);
    array[len] = NULL;
    return (array);
}
