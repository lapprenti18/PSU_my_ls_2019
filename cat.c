/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_c.c
*/

#include "my.h"

char *cat(char *start, char *line)
{
    int length_start = my_strlen(start);
    int length_line = my_strlen(line);
    char *reslt = NULL;
    int a = 0;

    reslt = malloc(sizeof(char) * (length_start + length_line + 2));
    for (; a < length_start; a += 1)
        reslt[a] = start[a];
    if (reslt[a - 1] != '/') {
        reslt[a] = '/';
        a += 1;
    }
    for (int b = 0; b < length_line; b += 1) {
        reslt[a] = line[b];
        a += 1;
    }
    reslt[a] = '\0';
    return (reslt);
}

void display(char **av, int a, struct stat size_buff, struct dirent *dr)
{
    lstat(av[a], &size_buff);
    rwx(size_buff.st_mode);
    the_rest(size_buff, av[a]);
    my_putstr(dr->d_name, 0, 1);
}

void reste(struct stat size_buff, struct dirent *dr, char *name)
{
    rwx(size_buff.st_mode);
    the_rest(size_buff, name);
    my_putstr(dr->d_name, 0, 1);
}

int print_tot(int boool, int total)
{
    write(1, "total ", 6);
    my_put_nbr(total, 0, 1);
    return (boool += 1);
}