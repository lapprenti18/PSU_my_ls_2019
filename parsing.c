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

int total_l(char **av, int a)
{
    char *name;
    DIR *dp;
    struct dirent *dr;
    int calc = 0;
    struct stat size_buff;

    dp = opendir(av[a]);
    while ((dr = readdir(dp)) != NULL) {
        name = dr->d_name;
        if (name[0] != '.') {
            lstat(name, &size_buff);
            calc += size_buff.st_blocks;
        }
    }
    return (calc/2);
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
    int jsp = 0;
    int total;
    int boool = 0;

    for (int a = 2; a != ac; a += 1) {
        test = file_and_error_l(av, a, size_buff);
        if (test == 1)
            error = 84;
        if (test != 1)
            dp = opendir(av[a]);
        if (dp && test != 1) {
            total = total_l(av, a);
            while (test != 1 && (dr = readdir(dp)) != NULL) {
                name = cat(av[a], dr->d_name);
                if (dr->d_name[0] != '.') {
                    if (lstat(name, &size_buff) < 0) {
                        jsp = 1;
                        break;
                    }
                    if (boool == 0) {
                        write(1, "total ", 6);
                        my_put_nbr(total, 0, 1);
                        boool += 1;
                    }
                    rwx(size_buff.st_mode);
                    the_rest(size_buff, name);
                    my_putstr(dr->d_name, 0, 1);
                }
            }
        }
        boool = 0;
        if (!dp && test != 1 || jsp == 1) {
            lstat(av[a], &size_buff);
            rwx(size_buff.st_mode);
            the_rest(size_buff, av[a]);
            my_putstr(dr->d_name, 0, 1);
        // printf("test = %d  jsp = %d\n", test, jsp);
        }
        jsp = 0;
        if (a + 1 < ac)
            write(1, "\n", 1);
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