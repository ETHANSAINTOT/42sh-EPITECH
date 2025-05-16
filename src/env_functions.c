/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** env_functions
*/

#include "my_42sh.h"

//env pairs are comprised of a string key with a corresponding string value
//a single pair can have a specific key
//
//creates an new env pair
static void create_env_pair(data_t *data, char *key, char *value)
{
    env_pair_t *env_pair = malloc(sizeof(env_pair_t));

    if (env_pair == NULL)
        return;
    env_pair->key = my_strdup(key);
    env_pair->value = my_strdup(value);
    env_pair->next = data->env_pair;
    data->env_pair = env_pair;
}

//overwrites the pair's value with the given key, if the pair
//doesn't exits, creates a new one
void set_env_pair(data_t *data, char *key, char *value)
{
    env_pair_t *env_pair = data->env_pair;

    while (env_pair != NULL) {
        if (my_strcmp(env_pair->key, key) == 0) {
            my_free(env_pair->value);
            env_pair->value = my_strdup(value);
            return;
        }
        env_pair = env_pair->next;
    }
    create_env_pair(data, key, value);
}

//display all the env pairs in a formated format
void display_env(data_t *data)
{
    env_pair_t *env_pair = data->env_pair;

    while (env_pair != NULL) {
        mini_printf("%s=%s\n", env_pair->key, env_pair->value);
        env_pair = env_pair->next;
    }
}

//get the value of the env pair with the given key
char *get_env_value(data_t *data, char *key)
{
    env_pair_t *env_pair = data->env_pair;

    while (env_pair != NULL) {
        if (my_strcmp(env_pair->key, key) == 0)
            return (env_pair->value);
        env_pair = env_pair->next;
    }
    return (NULL);
}

//delete the env pair with the given key
void delete_env_pair(data_t *data, char *key)
{
    env_pair_t **env_pair = NULL;
    env_pair_t *env_pair_to_free = NULL;

    if (data->env_pair == NULL)
        return;
    env_pair = &data->env_pair;
        while (*env_pair != NULL) {
            if (my_strcmp((*env_pair)->key, key) == 0) {
            env_pair_to_free = *env_pair;
            *env_pair = (*env_pair)->next;
            my_free(env_pair_to_free->key);
            my_free(env_pair_to_free->value);
            free(env_pair_to_free);
            return;
        }
        env_pair = &(*env_pair)->next;
    }
}

//frees all env pairs
void free_env(data_t *data)
{
    env_pair_t *env_pair_to_free = NULL;

    while (data->env_pair != NULL) {
        my_free(data->env_pair->key);
        my_free(data->env_pair->value);
        env_pair_to_free = data->env_pair;
        data->env_pair = data->env_pair->next;
        free(env_pair_to_free);
    }
}
