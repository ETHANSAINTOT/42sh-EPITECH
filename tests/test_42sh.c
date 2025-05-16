/*
** EPITECH PROJECT, 2025
** test_42sh
** File description:
** criterion tests for the 42sh project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_42sh.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

extern char **environ;

Test(shell, initialize_data, .init = redirect_all_std)
{
    data_t data = {0};

    initialize_data(&data);
    cr_assert_eq(data.input, NULL);
    cr_assert_eq(data.env, NULL);
    cr_assert_eq(data.status, 0);
    cr_assert_eq(data.is_invalid_null_command, false);
    cr_assert_eq(data.is_ambiguous_input_redirect, false);
    cr_assert_eq(data.is_ambiguous_output_redirect, false);
    cr_assert_eq(data.is_missing_redirect_name, false);
    cr_assert_eq(data.saved_stdin, 0);
    cr_assert_eq(data.saved_stdout, 0);
    cr_assert_eq(data.input_pipefd, 0);
    cr_assert_eq(data.output_pipefd, 0);
    cr_assert_eq(data.command, NULL);
    cr_assert_eq(data.env_pair, NULL);
    cr_assert_eq(data.aliases, NULL);
    cr_assert_eq(data.history_lenght, 0);
    cr_assert_eq(data.history, NULL);
}

Test(shell, parsing_test, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("TEST INPUT");

    initialize_data(&data);
    data.input = command_input;
    parse_input(&data);
    cr_assert_not_null(data.command, "First command is NULL");
    cr_assert_str_eq(data.command->command, "TEST",
        "Expected 'TEST', got '%s'", data.command->command);
    cr_assert_not_null(data.command->args, "Args array is NULL");
    cr_assert_str_eq(data.command->args[0], "INPUT",
        "Expected first arg to be 'INPUT', got '%s'", data.command->args[0]);
    cr_assert_null(data.command->args[1], "Expected only one argument");
    cr_assert_null(data.command->next, "Expected end of command list (NULL)");
}

Test(shell, echo_test, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("echo hello");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stdout();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    cr_assert_str_eq(buffer, "hello\n", "Expected 'hello\\n', got '%s'", buffer);
}

Test(shell, simple_builtin_cd, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("cd tests");
    FILE *output = NULL;
    char buffer[100];
    char initial_cwd[PATH_MAX];
    char cwd[PATH_MAX];

    getcwd(initial_cwd, sizeof(initial_cwd));
    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stdout();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "", "Expected nothing, got '%s'", buffer);
    getcwd(cwd, sizeof(cwd));
    cr_assert(strstr(cwd, "tests") != NULL, "Expected the current directory to be 'tests', but it is '%s'", cwd);
    chdir(initial_cwd);
}

Test(shell, fail_builtin_cd, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("cd fake_directory");
    FILE *output = NULL;
    char buffer[100];
    char initial_cwd[PATH_MAX];
    char cwd[PATH_MAX];

    getcwd(initial_cwd, sizeof(initial_cwd));
    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stderr();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "fake_directory: No such file or directory.\n", "Expected 'fake_directory: No such file or directory.\\n', got '%s'", buffer);
    getcwd(cwd, sizeof(cwd));
    cr_assert(strstr(cwd, "B-PSU-200-LIL-2-1-42sh-simon.dutal") != NULL, "Expected the current directory to be 'B-PSU-200-LIL-2-1-42sh-simon.dutal', but it is '%s'", cwd);
    chdir(initial_cwd);
}

Test(shell, too_many_args_builtin_cd, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("cd yes no");
    FILE *output = NULL;
    char buffer[100];
    char initial_cwd[PATH_MAX];
    char cwd[PATH_MAX];

    getcwd(initial_cwd, sizeof(initial_cwd));
    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stderr();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "cd: Too many arguments.\n", "Expected 'cd: Too many arguments.\\n', got '%s'", buffer);
    getcwd(cwd, sizeof(cwd));
    cr_assert(strstr(cwd, "B-PSU-200-LIL-2-1-42sh-simon.dutal") != NULL, "Expected the current directory to be 'B-PSU-200-LIL-2-1-42sh-simon.dutal', but it is '%s'", cwd);
    chdir(initial_cwd);
}


Test(shell, builtin_cd_home, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("cd");
    FILE *output = NULL;
    char buffer[100];
    char initial_cwd[PATH_MAX];
    char cwd[PATH_MAX];

    getcwd(initial_cwd, sizeof(initial_cwd));
    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stdout();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "", "Expected nothing, got '%s'", buffer);
    getcwd(cwd, sizeof(cwd));
    cr_assert(strstr(cwd, "/") != NULL, "Expected the current directory to be '/', but it is '%s'", cwd);
    chdir(initial_cwd);
}

Test(shell, builtin_cd_open_file, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("cd ./42sh_test");
    FILE *output = NULL;
    char buffer[100];
    char initial_cwd[PATH_MAX];
    char cwd[PATH_MAX];

    getcwd(initial_cwd, sizeof(initial_cwd));
    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stderr();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "./42sh_test: Not a directory.\n", "Expected './42sh_test: Not a directory.\\n', got '%s'", buffer);
    getcwd(cwd, sizeof(cwd));
    cr_assert(strstr(cwd, "B-PSU-200-LIL-2-1-42sh-simon.dutal") != NULL, "Expected the current directory to be 'B-PSU-200-LIL-2-1-42sh-simon.dutal', but it is '%s'", cwd);
    chdir(initial_cwd);
}

Test(shell, builtin_cd_no_perms, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("mkdir test_dir ; chmod 000 test_dir ; cd test_dir");
    FILE *output = NULL;
    char buffer[100];
    char initial_cwd[PATH_MAX];

    getcwd(initial_cwd, sizeof(initial_cwd));
    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stderr();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    cr_assert_str_eq(buffer, "test_dir: Permission denied.\n", "Expected 'test_dir: Permission denied.\\n', got '%s'", buffer);
    rmdir("test_dir");
    chdir(initial_cwd);
}

Test(shell, simple_setenv, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("setenv TEST this_is_a_test");
    int	i = 0;

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    cr_assert_str_eq(data.env_pair->key, "TEST", "Expected 'TEST' as key, got '%s'", data.env_pair->key);
    cr_assert_str_eq(data.env_pair->value, "this_is_a_test", "Expected 'this_is_a_test' as value, got '%s'", data.env_pair->value);
}

Test(shell, setenv_too_many_args, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("setenv you shall not pass");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stderr();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "setenv: Too many arguments.\n", "Expected 'setenv: Too many arguments.\\n', got '%s'", buffer);
}

Test(shell, setenv_must_begin_with_letter, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("setenv 59LIL yes");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stderr();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "setenv: Variable name must begin with a letter.\n", "Expected 'setenv: Variable name must begin with a letter.\\n', got '%s'", buffer);
}

Test(shell, setenv_alphanumeric_error, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("setenv LIL← yes");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stderr();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "setenv: Variable name must contain alphanumeric characters.\n", "Expected 'setenv: Variable name must contain alphanumeric characters.\\n', got '%s'", buffer);
}

Test(shell, display_env, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("setenv TEST this_is_a_test ; env");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stdout();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "TEST=this_is_a_test\n", "Expected 'TEST=this_is_a_test\\n', got '%s'", buffer);
}

Test(shell, display_env_with_setenv, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("setenv TEST this_is_a_test ; setenv");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stdout();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "TEST=this_is_a_test\n", "Expected 'TEST=this_is_a_test\\n', got '%s'", buffer);
}

Test(shell, simple_unsetenv, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("setenv TEST this_is_a_test ; unsetenv TEST");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stdout();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_neq(buffer, "TEST=this_is_a_test\n", "Not Expected 'TEST=this_is_a_test\\n', got '%s'", buffer);
}

Test(shell, unsetenv_too_few_args, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("setenv TEST this_is_a_test ; unsetenv");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stderr();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "unsetenv: Too few arguments.\n", "Expected 'unsetenv: Too few arguments.\\n', got '%s'", buffer);
}

Test(shell, simple_exit, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("exit");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stdout();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "exit\n", "Expected 'exit\\n', got '%s'", buffer);
}

Test(shell, command_exec_with_filepath, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("/bin/echo hello");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stdout();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "hello\n", "Expected 'hello\\n', got '%s'", buffer);
}

Test(shell, command_error_with_filepath, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("/boo/echo hello");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stderr();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "/boo/echo: Command not found.\n", "Expected '/boo/echo: Command not found.\\n', got '%s'", buffer);
}

Test(shell, command_error_no_permissions, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("cat /etc/shadow");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stderr();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "cat: /etc/shadow: Permission denied\n", "Expected 'cat: /etc/shadow: Permission denied\\n', got '%s'", buffer);
}


Test(shell, simple_history, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("echo test");

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    save_history_entry(&data);
    parse_input(&data);
    run_commands(&data);
    cr_assert_str_eq(data.history->command, "echo test", "Expected 'echo test' in data.history->command, got '%s'", data.history->command);
    cr_assert_eq(data.history->index, 1, "Expected '1' as index, got '%d'", data.history->index);
    cr_assert_not_null(data.history->time_stamp);
}

Test(shell, simple_redirect_right, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("echo hello > output.txt ; chmod 777 output.txt ; cat output.txt");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stdout();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "hello\n", "Expected 'hello\\n' in output.txt, got '%s'", buffer);
    unlink("output.txt");
}

Test(shell, redirect_right_replace, .init = redirect_all_std)
{
    data_t data;
    char *command_input = strdup("echo hello > output.txt ; echo world > output.txt ; chmod 777 output.txt ; cat output.txt");
    FILE *output = NULL;
    char buffer[100];

    initialize_data(&data);
    get_env(&data, environ);
    data.input = command_input;
    parse_input(&data);
    run_commands(&data);
    output = cr_get_redirected_stdout();
    rewind(output);
    fgets(buffer, sizeof(buffer), output);
    buffer[strlen(buffer)] = '\0';
    cr_assert_str_eq(buffer, "world\n", "Expected 'world\\n' in output.txt, got '%s'", buffer);
    unlink("output.txt");
}
