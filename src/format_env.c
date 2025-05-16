/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** format_env
*/

#include "my_42sh.h"

//get the number of env pairs
static int env_pairs_len(data_t *data)
{
    env_pair_t *env_pair = data->env_pair;
    int len = 0;

    if (env_pair == NULL)
        return 0;
    while (env_pair != NULL) {
        len++;
        env_pair = env_pair->next;
    }
    return (len);
}

//format the env pairs to be used by the execve function
char **format_env(data_t *data)
{
    env_pair_t *env_pair = data->env_pair;
    char **array = malloc(sizeof(char *) * (env_pairs_len(data) + 1));
    int i = 0;

    if (env_pair == NULL || array == NULL)
        return NULL;
    for (; env_pair != NULL; i++) {
        array[i] = malloc(sizeof(char) * (my_strlen(env_pair->key)
        + 1 + my_strlen(env_pair->value) + 1));
        if (array[i] != NULL) {
            my_strcpy(array[i], env_pair->key);
            array[i][my_strlen(env_pair->key)] = '=';
            my_strcpy(array[i] + my_strlen(env_pair->key) + 1,
            env_pair->value);
        }
        env_pair = env_pair->next;
    }
    array[i] = NULL;
    return array;
}
