/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** run_file
*/

#include "my_42sh.h"

//handle return values and signals
static void handle_status(data_t *data, int status)
{
    if (WIFSIGNALED(status)) {
        data->status = status;
        my_putstr(strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status)) {
            my_putstrerr(" (core dumped)");
        }
        if (!WCOREDUMP(status) && status == 11) {
            data->status = 139;
        }
        my_putstrerr("\n");
    } else {
        data->status = WEXITSTATUS(status);
    }
}

//run the prgramm and waits for it to finish
void run_file(data_t *data, char *file_path)
{
    pid_t pid = 0;
    int status = 0;
    char **env = format_env(data);

    open_pipes(data);
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "shell side error.\n");
    }
    if (pid == 0) {
        execve(file_path, data->command->command_content, env);
        fprintf(stderr, "%s: %s. Binary file not executable.\n",
            data->command->command, strerror(errno));
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        handle_status(data, status);
    }
    my_freestrarray(env);
    close_pipes(data);
}
