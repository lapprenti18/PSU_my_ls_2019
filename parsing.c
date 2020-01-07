/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_c.c
*/

#include "my.h"

char *date(char *str)
{
    char *date = malloc(sizeof(char) * 13);

    date[12] = '\0';
    for (int a = 4; a < 16; a += 1)
        date[a - 4] = str[a];
    return (date);
}

void print_permission(int ac, char **av)
{
    struct stat size_buff;
    struct passwd *user;
    struct group *groupe;
    struct time_t *time;
    char *str = malloc(sizeof(char) * 25);
    char *name;
    DIR *dp;
    struct dirent *dr;
    int total = 0;

    dp = opendir(".");
    write(1, "total ", 6);
    if ((dr = readdir(dp)) != NULL) {
        name = dr->d_name;
        lstat(name, &size_buff);
        my_put_nbr(size_buff.st_blocks);
        write(1, "\n", 1);
    }
    while ((dr = readdir(dp)) != NULL) {
        name = dr->d_name;
        if (name[0] != '.') {
            lstat(name, &size_buff);
            my_putstr( (S_ISDIR(size_buff.st_mode)) ? "d" : "-");
            my_putstr( (size_buff.st_mode & S_IRUSR) ? "r" : "-");
            my_putstr( (size_buff.st_mode & S_IWUSR) ? "w" : "-");
            my_putstr( (size_buff.st_mode & S_IXUSR) ? "x" : "-");
            my_putstr( (size_buff.st_mode & S_IRGRP) ? "r" : "-");
            my_putstr( (size_buff.st_mode & S_IWGRP) ? "w" : "-");
            my_putstr( (size_buff.st_mode & S_IXGRP) ? "x" : "-");
            my_putstr( (size_buff.st_mode & S_IROTH) ? "r" : "-");
            my_putstr( (size_buff.st_mode & S_IWOTH) ? "w" : "-");
            my_putstr( (size_buff.st_mode & S_IXOTH) ? "x" : "-");
            write(1, " ", 1);
            my_put_nbr(size_buff.st_nlink);
            write(1, " ", 1);
            user = getpwuid(size_buff.st_uid);
            my_putstr(user->pw_name);
            write(1, " ", 1);
            groupe = getgrgid(size_buff.st_gid);
            my_putstr(groupe->gr_name);
            write(1, " ", 1);
            my_put_nbr(size_buff.st_size);
            write(1, " ", 1);
            str = ctime(&size_buff.st_mtime);
            str = date(str);
            my_putstr(str);
            write(1, " ", 1);
            dr = readdir(dp);
            my_putstr(name);
            write (1, "\n", 1);
        }
    }
}

void ls_with_l(int ac, char **av)
{
    if (ac == 2) {
        print_permission(ac, av);
        return;
    // } else {
    // }

    }
}

void parsing(int ac, char **av)
{
    if (av[1][1] == 'l' && av[1][2] == '\0') {
        ls_with_l(ac, av);
        return;
    }
}
