/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_c.c
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        just_ls();
        return (0);
    }
    if (av[1][0] != '-') {
        ls_directory(ac, av);
        return (0);
    } else {
        parsing(ac, av);
    }
    return (0);
}