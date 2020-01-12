/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_c.c
*/

#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>

void just_ls(void);
int ls_directory(int ac, char **av);
int parsing(int ac, char **av);
void my_putstr(char *str, int space, int slash);
void my_put_nbr(int nb, int space, int slash);
int print_permission(int ac, char **av);
void rwx(int size_buff);
void the_rest(struct stat size_buff, char *name);
void total(void);
char *date(char *str);
int my_strlen(char *str);
char *cat(char *start, char *line);
void display(char **av, int a, struct stat size_buff, struct dirent *dr);
void reste(struct stat size_buff, struct dirent *dr, char *name);
int print_tot(int boool, int total);