/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** header
*/

#ifndef MY_42SH_H_
    #define MY_42SH_H_

    #include "my.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <time.h>

    static const char *const builtin_names[] = {
    "cd", "setenv", "unsetenv", "env", "exit",
    "history", "which", "alias", "unalias", NULL};

typedef struct data {
    char *input;
    char **env;
    int status;
    bool is_invalid_null_command;
    bool is_ambiguous_input_redirect;
    bool is_ambiguous_output_redirect;
    bool is_missing_redirect_name;
    int saved_stdin;
    int saved_stdout;
    int input_pipefd;
    int output_pipefd;
    int pipe1[2];
    int pipe2[2];
    struct command *command;
    struct env_pair *env_pair;
    struct alias *aliases;
    u_int history_lenght;
    struct history_entry *history;
} data_t;

typedef struct env_pair {
    char *key;
    char *value;
    struct env_pair *next;
} env_pair_t;

typedef struct command {
    char *command;
    char **args;
    char **command_content;
    char separator_type;
    bool is_output_append;
    char *output_trg;
    bool is_input_here;
    char *input_trg_word;
    struct command *next;
} command_t;

typedef struct history_entry {
    char *command;
    int index;
    time_t time_stamp;
    struct history_entry *next;
} history_entry_t;

typedef struct alias {
    char *name;
    char *command;
    struct alias *next;
} alias_t;

int main(int ac, char **av, char **env);
void check_args(char **av);
void get_env(data_t *data, char **env);
void initialize_data(data_t *data);
void main_loop(data_t *data);
void display_prompt(data_t *data);
void get_input(data_t *data);
void save_history_entry(data_t *data);
void parse_input(data_t *data);
void run_commands(data_t *data);
void exec_program(data_t *data);
void run_file(data_t *data, char *file_path);
void open_pipes(data_t *data);
void close_pipes(data_t *data);

bool builtin_cd(data_t *data);
bool builtin_setenv(data_t *data);
bool builtin_unsetenv(data_t *data);
bool builtin_env(data_t *data);
bool builtin_exit(data_t *data);
bool builtin_history(data_t *data);
bool builtin_alias(data_t *data);
bool builtin_unalias(data_t *data);
bool builtin_which(data_t *data);

void set_env_pair(data_t *data, char *key, char *);
void display_env(data_t *data);
char *get_env_value(data_t *data, char *key);
void delete_env_pair(data_t *data, char *key);
void free_env(data_t *data);
char **format_env(data_t *data);
void free_data(data_t *data);
void free_commands(data_t *data);

#endif /* MY_42SH_H_ */
