/*
** EPITECH PROJECT, 2022
** add new data
** File description:
** get the data from the .rdr file
*/
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_radar.h"
#include "my.h"

sfVector2f get_vector(int x, int y, int x_arrival, int y_arrival)
{
    sfVector2f vec = {x_arrival - x, y_arrival - y};
    return vec;
}
