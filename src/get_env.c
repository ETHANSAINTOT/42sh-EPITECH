/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** get_env
*/

#include "my_42sh.h"

//read and import the env values
void get_env(data_t *data, char **env)
{
    char **buff = NULL;

    data->env_pair = NULL;
    for (int i = 0; env[i] != NULL; i++) {
        buff = my_strsplit(env[i], "=", false);
        if (buff == NULL) {
            my_freestrarray(buff);
            continue;
        }
        set_env_pair(data, buff[0], my_strchr(env[i], '=') + 1);
        my_freestrarray(buff);
    }
}
