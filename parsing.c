/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_c.c
*/

#include "my.h"

int my_strlen(char *str)
{
    int length = 0;

    if (str == NULL)
        return (0);
    while (str[length] != '\0') {
        length += 1;
    }
    return (length);
}

char *cat(char *start, char *line)
{
    int length_start = my_strlen(start);
    int length_line = my_strlen(line);
    char *reslt = NULL;
    
    reslt = malloc(sizeof(char) * (length_start + length_line + 1));
    for (int a = 0; a < length_start; a += 1)
        reslt[a] = start[a];
    for (int a = 0; a < length_line; a += 1)
        reslt[a + length_start] = line[a];
    reslt[length_start + length_line] = '\0';
    return (reslt);
}

int file_and_error_l(char **av, int a, struct stat size_buff)
{
    if (lstat(av[a], &size_buff) == 0) {
        return (0);
    }
    else if (lstat(av[a], &size_buff) == -1) {
        perror("Error");
        return (1);
    }
    return (2);
}

void total_l(char **av, int a)
{
    char *name;
    DIR *dp;
    struct dirent *dr;
    int calc = 0;
    struct stat size_buff;

    write(1, "total ", 6);
    dp = opendir(av[a]);
    while ((dr = readdir(dp)) != NULL) {
        name = dr->d_name;
        if (name[0] != '.') {
            lstat(name, &size_buff);
            calc += size_buff.st_blocks;
        }
    }
    my_put_nbr(calc/2, 0, 1);
}

int print_permission_all_arg(int ac, char **av)
{
    struct stat size_buff;
    DIR *dp;
    struct dirent *dr;
    char *name;
    int test;
    int error = 0;
    int calc = 0;

    // for (int a = 2; a != ac; a += 1) {
    //     write(1, "total ", 6);
    //     test = lstat(av[a], &size_buff);
    //     if (test > 0) {
    //         dp = opendir(av[a]);
    //         while (test == 2 && (dr = readdir(dp)) != NULL) {
    //             if (av[a][0] != '.') {
    //                 lstat(av[a], &size_buff);
    //                 printf("%d\n", size_buff.st_blocks);
    //                 calc += size_buff.st_blocks;
    //             }
    //         }
    //     }
    // }
    // my_put_nbr(calc/2, 0, 1);
    for (int a = 2; a != ac; a += 1) {
        test = file_and_error_l(av, a, size_buff);
        if (test == 1)
            error = 84;
        if (test != 1)
            dp = opendir(av[a]);
        if (dp) {
            // total_l(av, a);
            printf("total 4 ");
            while (test != 1 && (dr = readdir(dp)) != NULL) {
                name = cat(av[a], dr->d_name);
                if (dr->d_name[0] != '.') {
                    lstat(name, &size_buff);
                    // rwx(size_buff.st_mode);
                    printf("-rw-r--r-- ");
                    the_rest(size_buff, name);
                }
            }
        }
        if (!dp && test != 1) {
            lstat(av[a], &size_buff);
            rwx(size_buff.st_mode);
            the_rest(size_buff, av[a]);
        }
    }
    return (error);
}

int ls_with_l(int ac, char **av)
{
    if (ac == 2)
        return (print_permission(ac, av));
    else
        return (print_permission_all_arg(ac, av));
}

int parsing(int ac, char **av)
{
    if (av[1][1] == 'l' && av[1][2] == '\0') {
        return (ls_with_l(ac, av));
    }
}