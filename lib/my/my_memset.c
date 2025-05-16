/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *ptr, int const value, uint const count)
{
    if (ptr == NULL)
        return (NULL);
    for (uint i = 0; i < count; i++) {
        ((int *) ptr)[i] = value;
    }
    return (ptr);
}
