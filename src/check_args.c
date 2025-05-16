/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** check_args
*/

#include "my_42sh.h"

//displays help flag
static void display_help(void)
{
    my_putstr("usage: 42sh [-h].\n");
    my_putstr("Minishell: UNIX command interpreter based on TCSH.\n");
    my_putstr("you can summon this help again with ./42sh -h.\n");
    my_putstr("builtins list:\n");
    my_putstr("cd [dir]\t\t: change working directory.\n");
    my_putstr("setenv [key] [value]\t: sets the key environment ");
    my_putstr("variable to value.\n");
    my_putstr("unsetenv [key]\t\t: unset the matching ");
    my_putstr("environment variable.\n");
    my_putstr("env\t\t\t: displays the environment variables.\n");
    my_putstr("exit [value]\t\t: exits with value as exit code.\n");
    my_putstr("\n");
}

//checks for help flag
void check_args(char **av)
{
    for (int i = 0; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-h") == 0 ||
            my_strcmp(av[i], "--help") == 0) {
            display_help();
            exit(0);
        }
    }
}
