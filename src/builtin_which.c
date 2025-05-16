/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** which built in
*/

#include "my_42sh.h"

//checks if command is a builtin
static bool is_builtin(char *cmd)
{
    for (int i = 0; builtin_names[i] != NULL; i++) {
        if (strcmp(cmd, builtin_names[i]) == 0) {
            my_putstr(cmd);
            printf(": shell built-in command.\n");
            return (true);
        }
    }
    return (false);
}

//creates full path to check
static char *build_path(char *dir, char *cmd)
{
    char *full_path = malloc(sizeof(char) *
        (strlen(dir) + strlen(cmd) + 2));

    if (full_path == NULL)
        return (NULL);
    strcpy(full_path, dir);
    full_path[strlen(dir)] = '/';
    strcpy(full_path + strlen(dir) + 1, cmd);
    return (full_path);
}

//checks if file exists and is executable
static bool is_executable(char *path)
{
    return (access(path, F_OK) == 0 && access(path, X_OK) == 0);
}

//checks command in a single path directory
static bool check_in_dir(char *dir, char *cmd)
{
    char *full_path = build_path(dir, cmd);
    bool result = false;

    if (full_path == NULL)
        return (false);
    if (is_executable(full_path)) {
        my_putstr(full_path);
        my_putchar('\n');
        result = true;
    }
    free(full_path);
    return (result);
}

//searches command in all PATH directories
static bool search_in_path(char *path, char *cmd)
{
    char **path_list = my_strsplit(path, ":", false);
    bool found = false;

    if (path_list == NULL)
        return (false);
    for (int i = 0; path_list[i] != NULL && !found; i++) {
        found = check_in_dir(path_list[i], cmd);
    }
    my_freestrarray(path_list);
    return (found);
}

//process single command argument
static bool process_command(data_t *data, char *cmd)
{
    char *path = get_env_value(data, "PATH");

    if (is_builtin(cmd))
        return (true);
    if (path == NULL || !search_in_path(path, cmd)) {
        my_putstr(cmd);
        printf(": Command not found.\n");
        return (false);
    }
    return (true);
}

//checks if which is called and locates commands
bool builtin_which(data_t *data)
{
    bool success = true;

    if (strcmp(data->command->command, "which") != 0)
        return (false);
    if (my_ptrarraylen((void **) data->command->args) == 0) {
        fprintf(stderr, "which: Too few arguments.\n");
        data->status = 1;
        return (true);
    }
    for (int i = 0; data->command->args[i] != NULL; i++) {
        if (!process_command(data, data->command->args[i]))
            success = false;
    }
    data->status = success ? 0 : 1;
    return (true);
}
