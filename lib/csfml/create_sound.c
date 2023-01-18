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
#include "my_csfml.h"

sfSound *create_sound(char *file_path)
{
    sfSoundBuffer *buff =
    sfSoundBuffer_createFromFile(file_path);
    sfSound *s = sfSound_create();
    sfSound_setBuffer(s, buff);
    return s;
}
