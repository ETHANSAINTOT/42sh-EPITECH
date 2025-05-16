##
## EPITECH PROJECT, 2025
## libmy
## File description:
## Makefile
##

LIBNAME = my

SRC	= my_putchar.c\
	  my_putcharerr.c\
	  my_putstr.c\
	  my_putstrerr.c\
	  my_putint.c\
	  my_putinterr.c\
	  my_strlen.c\
	  my_strcmp.c\
	  my_strncmp.c\
	  my_strdup.c\
	  my_strndup.c\
	  my_isalphanum.c\
	  my_countwords.c\
	  my_strwordarray.c\
	  my_do_char_match.c\
	  my_revstr.c\
	  my_strupcase.c\
	  my_strlowercase.c\
	  my_intlen.c\
	  my_putfloat.c\
	  my_strstr.c\
	  mini_printf.c\
	  my_freestrarray.c\
	  my_strsplit.c\
	  my_segfault.c\
	  my_putstrfallback.c\
	  my_atoi.c\
	  my_ptrarraylen.c\
	  my_free.c\
	  my_strchr.c\
	  my_strarraydup.c\
	  my_strcpy.c\
	  my_strncpy.c\
	  my_isalpha.c\
	  my_settextcol.c\
	  my_settextbcol.c\
	  my_setbackgroundcol.c\
	  my_setunderlinecol.c\
	  my_movecursor.c\
	  my_clearscreen.c\
	  my_hidecursor.c\
	  my_showcursor.c\
	  my_memset.c\
	  my_putstrurl.c\
	  my_strpbrk.c\
	  my_strcount.c\
	  my_strreplace.c\
	  my_wordlen.c\
	  my_wordleninv.c\
	  my_isadir.c\

CC	= gcc

OBJ     = $(SRC:.c=.o)

FLAGS	= -Wall -Wextra -fanalyzer

ifeq ($(MAKECMDGOALS),debug)
    CFLAGS += -g
endif

all: $(OBJ)
	ar rcs lib$(LIBNAME).a $(OBJ)
	cp lib$(LIBNAME).a -t ../
	mkdir -p ../../include
	cp $(LIBNAME).h -t ../../include/
	echo "lib$(LIBNAME) built"

debug: $(OBJ)
	ar rcs lib$(LIBNAME).a $(OBJ)
	cp lib$(LIBNAME).a -t ../
	mkdir -p ../../include
	cp $(LIBNAME).h -t ../../include/
	echo "lib$(LIBNAME) built debug mode"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f lib$(LIBNAME).a
	@rm -f ../lib$(LIBNAME).a
