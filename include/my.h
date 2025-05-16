/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** header
*/

#ifndef LIBMY_H
    #define LIBMY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <dirent.h>
    #include <sys/stat.h>

    #define UNUSED __attribute__ ((unused))

void my_putchar(char const c);
void my_putcharerr(char const c);
void my_putstr(char const *str);
void my_putstrerr(char const *str);
void my_putint(int const nb);
void my_putinterr(int const nb);
int my_strlen(char const *str);
int my_strcmp(char const *sc, char const *s2);
int my_strncmp(char const *sc, char const *s2, int const n);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int const n);
int my_isalphanum(char const c);
int my_countwords(char const *str);
char **my_strwordarray(char const *str);
int my_do_char_match(char const a, char const b);
char *my_revstr(char const *str);
char *my_strupcase(char const *str);
char *my_strlowercase(char const *str);
int my_intlen(int const nb);
void my_putfloat(float const nb, int const acc);
char *my_strstr(char const *str, char const *sub);
int mini_printf(char const *str, ...);
void my_freestrarray(char **arr);
char *my_readfile(char const *trg);
char **my_strsplit(char const *str, char *const filter,
    bool const keep_separator);
void my_segfault(void);
void my_putstrfallback(char const *str, char const *errstr);
int my_atoi(char const *str);
int my_ptrarraylen(void **array);
void my_free(void *ptr);
char *my_strchr(char *str, char const c);
bool my_isfileindir(char const *filename, char const *dirname);
char **my_strarraydup(char **src);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int const n);
int my_isalpha(char const c);
bool my_isadir(char const *file_path);
void *my_memset(void *ptr, int const value, uint const count);
char *my_strpbrk(char *str, char const *chars);
int my_strcount(char *str, char const *trg);
char *my_strreplace(char *str, char const *trg, char const *sub);
void my_writetofile(char const *trg, char const *str);
void my_appendtofile(char const *trg, char const *str);
int my_wordlen(char const *str, char *const filter);
int my_wordleninv(char const *str, char *const filter);
char *my_readfd(int const fd);

    #define ABS(a) ((a) < 0 ) ? (-a) : (a)
    #define MIN(a, b) ((a) < (b)) ? (a) : (b)
    #define MAX(a, b) ((a) > (b)) ? (a) : (b)

void my_settextcol(u_char const r, u_char const g, u_char const b);
void my_settextbcol(u_char const r, u_char const g, u_char const b);
void my_setbackgroundcol(u_char const r, u_char const g, u_char const b);
void my_setunderlinecol(u_char const r, u_char const g, u_char const b);
void my_putstrurl(char const *str, char const *url);
void my_movecursor(u_int const x, u_int const y);
void my_clearscreen(void);
void my_hidecursor(void);
void my_showcursor(void);

    #define COL_RESET     "\033[0m"

    #define COL_BOLD      "\033[1m"
    #define COL_DIM       "\033[2m"
    #define COL_ITALIC    "\033[3m"
    #define COL_UNDERLINE "\033[4m"
    #define COL_BLINK     "\033[5m"
    #define COL_REVERSE   "\033[7m"
    #define COL_HIDDEN    "\033[8m"
    #define COL_STRIKE    "\033[9m"
    #define COL_DUNDERLINE "\033[21m"
    #define COL_OVERLINE  "\033[53m"

    #define COL_BLACK     "\033[30m"
    #define COL_RED       "\033[31m"
    #define COL_GREEN     "\033[32m"
    #define COL_YELLOW    "\033[33m"
    #define COL_BLUE      "\033[34m"
    #define COL_MAGENTA   "\033[35m"
    #define COL_CYAN      "\033[36m"
    #define COL_WHITE     "\033[37m"
    #define COL_DEFAULT   "\033[39m"

    #define COL_BBLACK    "\033[40m"
    #define COL_BRED      "\033[41m"
    #define COL_BGREEN    "\033[42m"
    #define COL_BYELLOW   "\033[43m"
    #define COL_BBLUE     "\033[44m"
    #define COL_BMAGENTA  "\033[45m"
    #define COL_BCYAN     "\033[46m"
    #define COL_BWHITE    "\033[47m"
    #define COL_BDEFAULT  "\033[49m"

    #define COL_IBLACK    "\033[90m"
    #define COL_IRED      "\033[91m"
    #define COL_IGREEN    "\033[92m"
    #define COL_IYELLOW   "\033[93m"
    #define COL_IBLUE     "\033[94m"
    #define COL_IMAGENTA  "\033[95m"
    #define COL_ICYAN     "\033[96m"
    #define COL_IWHITE    "\033[97m"

    #define COL_IBBLACK   "\033[100m"
    #define COL_IBRED     "\033[101m"
    #define COL_IBGREEN   "\033[102m"
    #define COL_IBYELLOW  "\033[103m"
    #define COL_IBBLUE    "\033[104m"
    #define COL_IBMAGENTA "\033[105m"
    #define COL_IBCYAN    "\033[106m"
    #define COL_IBWHITE   "\033[107m"

#endif
