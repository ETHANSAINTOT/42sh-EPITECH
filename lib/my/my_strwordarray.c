/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_strwordarray
*/

#include "my.h"

static int alphawordlen(char const *str)
{
    int len = 0;

    while (my_isalphanum(str[len]) == 1) {
        len++;
    }
    return (len);
}

static void read_words(char **array, char const *str)
{
    int c = 0;
    int word_len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalphanum(str[i]) == 1) {
            word_len = alphawordlen(str + i);
            array[c] = my_strndup(str + i, word_len);
            i += word_len - 1;
            c++;
        }
    }
}

char **my_strwordarray(char const *str)
{
    int len = my_countwords(str);
    char **array = NULL;

    if (str == NULL)
        return (NULL);
    array = malloc((len + 1) * sizeof(char *));
    if (array == NULL)
        return (NULL);
    read_words(array, str);
    array[len] = NULL;
    return (array);
}
