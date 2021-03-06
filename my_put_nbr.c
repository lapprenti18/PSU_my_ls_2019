/*
** EPITECH PROJECT, 2019
** MY_PUT_NBR
** File description:
** Display the number given as a parameter
*/

#include "my.h"

void    my_putchar(char c)
{
    write (1, &c, 1);
}

void    my_limit_int(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
    return;
}

void    my_put_nbr(int nb, int space, int slash)
{
    if (nb == (-2147483648)) {
        my_limit_int();
        return;
    }
    if (nb <0){
        my_putchar('-');
        nb = -nb;
    }

    if (nb >= 10) {
        my_put_nbr(nb/10, 0, 0);
        my_putchar(nb % 10 + '0');
    } else {
        my_putchar(nb + '0');
    }
    if (space == 1)
        write(1, " ", 1);
    if (slash == 1)
        write(1, "\n", 1);
}