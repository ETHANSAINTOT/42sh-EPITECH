/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** exec_program
*/

#include "my_42sh.h"

//creates the path of the file to be run
static char *create_file_path(char *path, char *file_name)
{
    char *file_path = malloc((my_strlen(path) + 1
    + my_strlen(file_name) + 1) * sizeof(char));
    int i = 0;

    if (file_path == NULL)
        return (NULL);
    for (int j = 0; path[j] != '\0'; j++) {
        file_path[i] = path[j];
        i++;
    }
    file_path[i] = '/';
    i++;
    for (int j = 0; file_name[j] != '\0'; j++) {
        file_path[i] = file_name[j];
        i++;
    }
    file_path[i] = '\0';
    return (file_path);
}

//checks if the path is valid
static bool check_if_path_valid_verbose(data_t *data, char *file_path)
{
    if (file_path == NULL)
        return (false);
    if (access(file_path, F_OK) != 0) {
        fprintf(stderr, "%s: Command not found.\n", data->command->command);
        data->status = 1;
        return (false);
    }
    if (access(file_path, X_OK) != 0) {
        fprintf(stderr, "%s: Permission denied.\n", data->command->command);
        data->status = 1;
        return (false);
    }
    if (my_isadir(file_path)) {
        fprintf(stderr, "%s: Permission denied.\n", data->command->command);
        data->status = 1;
        return (false);
    }
    return (true);
}

//checks if the path is valid
static bool check_if_path_valid_path(data_t *data, char *file_path)
{
    if (file_path == NULL)
        return (false);
    if (access(file_path, F_OK) != 0) {
        return (false);
    }
    if (access(file_path, X_OK) != 0) {
        fprintf(stderr, "%s: Permission denied.\n", file_path);
        data->status = 1;
        return (false);
    }
    if (my_isadir(file_path)) {
        fprintf(stderr, "%s: Permission denied.\n", file_path);
        data->status = 1;
        return (false);
    }
    return (true);
}

//executes from the root dir
static void try_exec_root(data_t *data)
{
    char *file_path = NULL;

    file_path = my_strdup(data->command->command);
    if (check_if_path_valid_verbose(data, file_path)) {
        run_file(data, file_path);
    }
    my_free(file_path);
}

//executes from the cwd
static void try_exec_cwd(data_t *data)
{
    char *file_path = NULL;

    file_path = create_file_path(get_env_value(data, "PWD"),
    data->command->command);
    if (check_if_path_valid_verbose(data, file_path)) {
        run_file(data, file_path);
    }
    my_free(file_path);
}

//executes with path
static void try_exec_paths(data_t *data)
{
    char *file_path = NULL;
    char **path_list = my_strsplit(get_env_value(data, "PATH"), ":", false);

    for (int i = 0; path_list != NULL && path_list[i] != NULL; i++) {
        file_path = create_file_path(path_list[i], data->command->command);
        if (file_path == NULL)
            continue;
        if (check_if_path_valid_path(data, file_path)) {
            run_file(data, file_path);
            free(file_path);
            my_freestrarray(path_list);
            return;
        }
        my_free(file_path);
    }
    fprintf(stderr, "%s: Command not found.\n", data->command->command);
    data->status = 1;
    my_freestrarray(path_list);
}

//checks if a programm execution is called
void exec_program(data_t *data)
{
    if (data->command->command[0] == '/') {
        try_exec_root(data);
        return;
    }
    if (my_strstr(data->command->command, "./") == data->command->command ||
        my_strchr(data->command->command, '/') != NULL) {
        try_exec_cwd(data);
        return;
    }
    try_exec_paths(data);
}
