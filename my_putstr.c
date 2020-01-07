/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** ok
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void   my_putchar12(char c)
{
    write(1, &c, 1);
}

int    my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0'){
        my_putchar12(str[i]);
        i++;
    }
    return (0);
}
