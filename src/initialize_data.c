/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** initialyse_data
*/

#include "my_42sh.h"

void initialize_data(data_t *data)
{
    *data = (data_t) {NULL, NULL,
        0,
        false, false, false, false,
        0, 0, 0, 0, {0, 0}, {0, 0},
        NULL,
        NULL,
        NULL,
        0, NULL};
}
