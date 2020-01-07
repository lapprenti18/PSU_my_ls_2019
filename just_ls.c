/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_c.c
*/

#include "my.h"

void just_ls(void)
{
    DIR *dp = opendir(".");
    struct dirent *dr;
    char *str;

    while ((dr = readdir(dp)) != NULL) {
        str = dr->d_name;
        if (str[0] != '.') {
            my_putstr(str);
            write (1, "\n", 1);
        }
    }
}

void ls_directory(int ac, char **av)
{
    DIR *dp;
    struct dirent *dr;
    char *str;

    for (int a = 1; a != ac; a += 1) {
        dp = opendir(av[a]);
        while ((dr = readdir(dp)) != NULL) {
            str = dr->d_name;
            if (str[0] != '.') {
                my_putstr(str);
                write (1, "\n", 1);
            }
        }
        if (a + 1 < ac)
            write(1, "\n", 1);
    }
}