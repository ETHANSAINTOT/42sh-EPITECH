##
## EPITECH PROJECT, 2025
## wolf3d
## File description:
## Makefile
##

NAME	= 42sh
TEST_BIN = tests_42sh

SRC	= src/main.c\
	  src/check_args.c\
	  src/get_env.c\
	  src/initialize_data.c\
	  src/main_loop.c\
	  src/display_prompt.c\
	  src/get_input.c\
	  src/save_history_entry.c\
	  src/parse_input.c\
	  src/run_commands.c\
	  src/manage_pipes.c\
	  src/exec_program.c\
	  src/run_file.c\
	  src/builtin_cd.c\
	  src/builtin_setenv.c\
	  src/builtin_unsetenv.c\
	  src/builtin_env.c\
	  src/builtin_exit.c\
	  src/builtin_history.c\
	  src/builtin_alias.c\
	  src/builtin_unalias.c\
	  src/builtin_which.c\
	  src/env_functions.c\
	  src/format_env.c\
	  src/free_data.c\

OBJ	= $(SRC:.c=.o)

OBJ_TESTS	= $(SRC_TESTS:.c=.o)

TESTS_SRC = tests/test_42sh.c
TESTS_OBJ = $(TESTS_SRC:.c=.o)

LIB	= lib/libmy.a

CC	= gcc

WFLAGS  = -Wall -Wextra -fanalyzer
CFLAGS	= -I include -L lib -l my

ifeq ($(MAKECMDGOALS),debug)
    CFLAGS += -g
endif
ifeq ($(MAKECMDGOALS),test)
    CFLAGS += -g
endif

all: $(NAME)

debug: $(NAME)_debug

$(NAME): $(LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(WFLAGS)

$(NAME)_debug: $(LIB) $(OBJ)
	$(CC) -o $(NAME)_debug $(OBJ) $(CFLAGS) $(WFLAGS)

clean_tests:
	@rm -f $(NAME)_test
	@rm -f *.gcda
	@rm -f *.gcno

unit_tests: $(LIB)
	$(CC) $(filter-out src/main.c,$(SRC)) $(TESTS_SRC) $(CFLAGS) \
-o $(NAME)_test --coverage -lcriterion

tests_run: clean_tests unit_tests
	./$(NAME)_test || true
	gcovr --exclude tests/
	gcovr --exclude tests/ --txt-metric branch

clean:
	@$(MAKE) clean -sC lib/my
	@rm -f $(OBJ)
	@rm -f $(TESTS_OBJ)

fclean: clean clean_tests
	@$(MAKE) fclean -sC lib/my
	@rm -f $(NAME)
	@rm -f $(NAME)_debug

re: fclean all

run: all
	./$(NAME)

$(LIB):
	@$(MAKE) -sC lib/my

test: debug
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all \
	./$(NAME)_debug
