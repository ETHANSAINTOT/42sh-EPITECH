/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** manage_pipes.c
*/

#include "my_42sh.h"

static void open_output_file(data_t *data)
{
    int fd = 0;

    data->saved_stdout = dup(STDOUT_FILENO);
    if (data->command->is_output_append) {
        fd = open(data->command->output_trg, O_CREAT | O_WRONLY | O_APPEND);
    } else {
        fd = open(data->command->output_trg, O_CREAT | O_WRONLY,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    }
    if (fd < 0)
        return;
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

static void open_input_file(data_t *data)
{
    int fd = 0;

    data->saved_stdin = dup(STDIN_FILENO);
    fd = open(data->command->input_trg_word, O_RDONLY);
    if (fd < 0)
        return;
    dup2(fd, STDIN_FILENO);
    close(fd);
}

static void start_reading_from_pipe(data_t *data)
{
    if (data->pipe2[0] > 0 && data->pipe2[1] == 0) {
        data->saved_stdin = dup(STDIN_FILENO);
        dup2(data->pipe2[0], STDIN_FILENO);
        return;
    }
    if (data->pipe1[0] > 0 && data->pipe1[1] == 0) {
        data->saved_stdin = dup(STDIN_FILENO);
        dup2(data->pipe1[0], STDIN_FILENO);
        return;
    }
}

static void start_writing_to_pipe(data_t *data)
{
    if (data->pipe1[0] == 0 && data->pipe1[1] == 0) {
        if (pipe(data->pipe1) == -1)
            return;
        data->saved_stdout = dup(STDOUT_FILENO);
        dup2(data->pipe1[1], STDOUT_FILENO);
        return;
    }
    if (data->pipe2[0] == 0 && data->pipe2[1] == 0) {
        if (pipe(data->pipe2) == -1)
            return;
        data->saved_stdout = dup(STDOUT_FILENO);
        dup2(data->pipe2[1], STDOUT_FILENO);
        return;
    }
}

//handle redirections and piping
void open_pipes(data_t *data)
{
    if (data->command->output_trg != NULL) {
        open_output_file(data);
    }
    if (data->command->input_trg_word != NULL) {
        if (data->command->is_input_here) {
        } else {
            open_input_file(data);
        }
    }
    start_reading_from_pipe(data);
    if (data->command->separator_type == '|') {
        start_writing_to_pipe(data);
    }
}

static void close_output_file(data_t *data)
{
    dup2(data->saved_stdout, STDOUT_FILENO);
    close(data->saved_stdout);
}

static void close_input_file(data_t *data)
{
    dup2(data->saved_stdin, STDIN_FILENO);
    close(data->saved_stdin);
}

static void stop_reading_from_pipe(data_t *data)
{
    if (data->pipe1[0] > 0 && data->pipe1[1] == 0) {
        close(data->pipe1[0]);
        data->pipe1[0] = 0;
        dup2(data->saved_stdin, STDIN_FILENO);
        close(data->saved_stdin);
        return;
    }
    if (data->pipe2[0] > 0 && data->pipe2[1] == 0) {
        close(data->pipe2[0]);
        data->pipe2[0] = 0;
        dup2(data->saved_stdin, STDIN_FILENO);
        close(data->saved_stdin);
        return;
        }
}

static void stop_writing_to_pipe(data_t *data)
{
    if (data->pipe1[0] > 0 && data->pipe1[1] > 0) {
        close(data->pipe1[1]);
        data->pipe1[1] = 0;
        dup2(data->saved_stdout, STDOUT_FILENO);
        return;
    }
    if (data->pipe2[0] > 0 && data->pipe2[1] > 0) {
        close(data->pipe2[1]);
        data->pipe2[1] = 0;
        dup2(data->saved_stdout, STDOUT_FILENO);
        return;
    }
}

//closes opened pipes
void close_pipes(data_t *data)
{
    if (data->command->output_trg != NULL) {
        close_output_file(data);
    }
    if (data->command->input_trg_word != NULL) {
        if (data->command->is_input_here) {
        } else {
            close_input_file(data);
        }
    }
    stop_reading_from_pipe(data);
    if (data->command->separator_type == '|') {
        stop_writing_to_pipe(data);
    }
}
