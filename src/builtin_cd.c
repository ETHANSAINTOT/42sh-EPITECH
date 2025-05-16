/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** builtin_cd
*/

#include "my_42sh.h"

//update env to new cwd
static void update_env_after_cd(data_t *data)
{
    char *buff = malloc(sizeof(char) * PATH_MAX);
    char *pwd = NULL;

    if (buff == NULL)
        return;
    getcwd(buff, PATH_MAX);
    pwd = my_strndup(buff, my_strlen(buff));
    if (pwd == NULL)
        return;
    set_env_pair(data, "OLDPWD", get_env_value(data, "PWD"));
    set_env_pair(data, "PWD", buff);
    free(pwd);
    free(buff);
}

//checks if dir exits and is valid
static bool check_dir(data_t *data, char *dir)
{
    if (access(dir, F_OK) != 0) {
        fprintf(stderr, "%s: No such file or directory.\n",
        data->command->args[0]);
        data->status = 1;
        return (true);
    }
    if (access(dir, R_OK) != 0) {
        fprintf(stderr, "%s: Permission denied.\n",
        data->command->args[0]);
        data->status = 1;
        return (true);
    }
    if (my_isadir(dir) == false) {
        fprintf(stderr, "%s: Not a directory.\n",
        data->command->args[0]);
        data->status = 1;
        return (true);
    }
    return (false);
}

//change cwd and updates env
static void change_dir(data_t *data, char *dir)
{
    int status = 0;

    if (dir == NULL)
        return;
    if (check_dir(data, dir) == true)
        return;
    status = chdir(dir);
    if (status == -1) {
        data->status = 1;
        fprintf(stderr, "%s: No such file or directory.\n",
            data->command->args[0]);
        return;
    }
    data->status = 0;
    update_env_after_cd(data);
}

//checks args
static bool evaluate_cd_args(data_t *data)
{
    if (my_ptrarraylen((void **) data->command->args) == 0) {
        change_dir(data, get_env_value(data, "HOME"));
        return (true);
    }
    if (my_ptrarraylen((void **) data->command->args) == 1 &&
        my_strcmp(data->command->args[0], "-") == 0) {
        change_dir(data, get_env_value(data, "OLDPWD"));
        return (true);
    }
    if (my_ptrarraylen((void **) data->command->args) == 1) {
        change_dir(data, data->command->args[0]);
        return (true);
    }
    return (false);
}

//checks if cd is called
bool builtin_cd(data_t *data)
{
    if (my_strcmp(data->command->command, "cd") == 0) {
        if (evaluate_cd_args(data) == true) {
            return (true);
        }
        data->status = 1;
        fprintf(stderr, "cd: Too many arguments.\n");
        return (true);
    }
    return (false);
}
