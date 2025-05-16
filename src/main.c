/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** main
*/

#include "my_42sh.h"

//initializes program
int main(UNUSED int ac, char **av, char **env)
{
    data_t data;

    initialize_data(&data);
    check_args(av);
    get_env(&data, env);
    main_loop(&data);
    return (0);
}
