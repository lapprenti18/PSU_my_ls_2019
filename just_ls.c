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
        if (str[0] != '.')
            my_putstr(str, 0, 1);
    }
}

int file_and_error(char **av, int a, struct stat size_buff)
{
    if (lstat(av[a], &size_buff) == 0)
        return (0);
    else if (lstat(av[a], &size_buff) == -1) {
        perror("Error");
        return (1);
    }
    return (2);
}

void print(DIR *dp, struct dirent *dr, int test)
{
    char *str;

    while ((dr = readdir(dp)) != NULL) {
        str = dr->d_name;
        if (str[0] != '.')
            my_putstr(str, 0, 1);
    }
}

int ls_directory(int ac, char **av)
{
    DIR *dp;
    struct dirent *dr;
    struct stat size_buff;
    int error = 0;
    int test = 0;
    int a;

    for (int a = 1; a != ac; a += 1) {
        test = file_and_error(av, a, size_buff);
        if (test == 1)
            error = 84;
        if (test != 1)
            dp = opendir(av[a]);
        if (dp)
            print(dp, dr, test);
        if (!dp && test != 1)
            my_putstr(av[a], 0, 1);
        if (a + 1 < ac)
            write(1, "\n", 1);
    }
    return (error);
}

// int ls_directory(int ac, char **av)
// {
//     DIR *dp;
//     struct dirent *dr;
//     char *str;

//     for (int a = 1; a != ac; a += 1) {
//         dp = opendir(av[a]);
//         while ((dr = readdir(dp)) != NULL) {
//             str = dr->d_name;
//             if (str[0] != '.')
//                 my_putstr(str, 0, 1);
//         }
//         if (a + 1 < ac)
//             write(1, "\n", 1);
//     }
//     return (0);
// }