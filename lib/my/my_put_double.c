/*
** EPITECH PROJECT, 2022
** my_put_double
** File description:
** print double
*/

#include "my.h"

int my_put_double(double db, long precision)
{
    int nb = db;

    my_put_nbr(nb);
    my_putchar('.');
    while (precision > 0) {
        db *= 10;
        nb = db;
        nb = nb % 10;
        my_put_nbr(nb);
        precision -= 1;
    }
    return 1;
}
