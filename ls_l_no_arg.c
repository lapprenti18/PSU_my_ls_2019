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

void total(void)
{
    char *name;
    DIR *dp;
    struct dirent *dr;
    int calc = 0;
    struct stat size_buff;

    write(1, "total ", 6);
    dp = opendir(".");
    while ((dr = readdir(dp)) != NULL) {
        name = dr->d_name;
        if (name[0] != '.') {
            lstat(name, &size_buff);
            calc += size_buff.st_blocks;
        }
    }
    my_put_nbr(calc/2, 0, 1);
}

void the_rest(struct stat size_buff, char *name)
{
    struct passwd *user;
    struct group *groupe;
    char *str = malloc(sizeof(char) * 25);

    my_put_nbr(size_buff.st_nlink, 1, 0);
    user = getpwuid(size_buff.st_uid);
    my_putstr(user->pw_name, 1, 0);
    groupe = getgrgid(size_buff.st_gid);
    my_putstr(groupe->gr_name, 1, 0);
    my_put_nbr(size_buff.st_size, 1, 0);
    str = ctime(&size_buff.st_mtime);
    str = date(str);
    my_putstr(str, 1, 0);
    my_putstr(name, 0, 1);
}

void rwx(int size_buff)
{
    my_putstr((S_ISDIR(size_buff)) ? "d" : "-", 0, 0);
    my_putstr((size_buff & S_IRUSR) ? "r" : "-", 0, 0);
    my_putstr((size_buff & S_IWUSR) ? "w" : "-", 0, 0);
    my_putstr((size_buff & S_IXUSR) ? "x" : "-", 0, 0);
    my_putstr((size_buff & S_IRGRP) ? "r" : "-", 0, 0);
    my_putstr((size_buff & S_IWGRP) ? "w" : "-", 0, 0);
    my_putstr((size_buff & S_IXGRP) ? "x" : "-", 0, 0);
    my_putstr((size_buff & S_IROTH) ? "r" : "-", 0, 0);
    my_putstr((size_buff & S_IWOTH) ? "w" : "-", 0, 0);
    if (size_buff & __S_ISVTX)
        my_putstr((size_buff & S_IXOTH) ? "t" : "-", 1, 0);
    else
        my_putstr((size_buff & S_IXOTH) ? "x" : "-", 1, 0);
}

int print_permission(int ac, char **av)
{
    struct stat size_buff;
    DIR *dp;
    struct dirent *dr;
    char *name;

    total();
    dp = opendir(".");
    while ((dr = readdir(dp)) != NULL) {
        name = dr->d_name;
        if (name[0] != '.') {
            lstat(name, &size_buff);
            rwx((int)size_buff.st_mode);
            the_rest(size_buff, name);
        }
    }
    return (0);
}