/*
** EPITECH PROJECT, 2022
** generate
** File description:
** generate a map for my_radar
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"


static void create_aircrafts(FILE *inputFile, int a)
{
    for (int i = 0; i < a; i++) {
        int x = rand() % 1900;
        int y = rand() % 1000;
        int x2 = rand() % 1900;
        int y2 = rand() % 1000;
        int s = rand() % 20 + 1;
        int d = rand() % (10 + (a / 2) );
        fprintf(inputFile, "A %d %d %d %d %d %d\n",
        x, y, x2, y2, s, d);
    }
}

static void create_towers(FILE *inputFile, int t)
{
    for (int i = 0; i < t; i++) {
        int x = rand() % 1900;
        int y = rand() % 1000;
        int radius = rand() % 20 + 10;
        fprintf(inputFile, "T %d %d %d\n", x, y, radius);
    }
}

int generate(int argc, char **argv)
{
    srand(time(NULL));
    int a;
    int t;
    char *file_name;
    file_name = (argc < 5) ? "script.rdr" : argv[4];
    t = (argc < 4) ? rand() % 3 : my_str_to_int(argv[3]);
    a = (argc < 3) ? rand() % 300 : my_str_to_int(argv[2]);
    FILE *inputFile;
    inputFile = fopen(file_name, "w");
    create_aircrafts(inputFile, a);
    create_towers(inputFile, t);
    return 1;
}
