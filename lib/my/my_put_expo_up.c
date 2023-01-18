/*
** EPITECH PROJECT, 2022
** my_put_expo
** File description:
** print expodential
*/

#include "my.h"

void put_expo_up(double db, int count, int precision)
{
    my_put_double(db, precision);
    my_putchar('E');
    if (count < 0) {
        my_putchar('-');
        if (count > -10)
            my_putchar('0');
        my_put_nbr(count);
    }
    if (count > 0) {
        my_putchar('+');
        if (count < 10)
            my_putchar('0');
        my_put_nbr(count);
    }
}

int my_put_exponential_up(double db, int precision)
{
    int nb = db;
    int count = 0;

    if (db < 0) {
        while (nb < 10) {
            db *= 10;
            count -= 1;
            nb = db;
        }
    }
    if (db > 10) {
        while (nb > 10) {
            db /= 10;
            count += 1;
            nb = db;
        }
    }
    put_expo_up(db, count, precision);
    return 1;
}
