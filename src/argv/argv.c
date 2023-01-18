/*
** EPITECH PROJECT, 2022
** argv
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

static int is_wrong_character(char b)
{
    if ( (48 <= b && b <= 59)
    || b == 'T' || b == 'A' || b == ' ' || b == '\n') {
        return 0;
    }
    return 1;
}

int get_argv(int argc, char **argv, struct aircraft **a, struct tower **t)
{
    if (argc < 2) return 84;
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) return 84;
    fill_structures(fd, a, t, 0);
    return 0;
}

int fill_structures(int fd, struct aircraft **a, struct tower **t, int stop)
{
    if (stop == 1) return 0;
    char data_buffer[100] = "\0";
    char buff[1] = "\0";
    int i = 0;
    for (;buff[0] != '\n'; i++) {
        if (read(fd, buff, 1) == 0) {
            stop = 1;
            break;
        }
        if (is_wrong_character(buff[0]) == 1) return 84;
        data_buffer[i] = buff[0];
    }
    data_buffer[i - 1] = '\0';
    if (stop == 0) add_new_data(a, t, my_str_to_word_array(data_buffer) );
    return fill_structures(fd, a, t, stop);
    return 0;
}
    //get line
    //  si A -> fill A return 0 / 84
    //  si T -> fill T return 0 / 84
