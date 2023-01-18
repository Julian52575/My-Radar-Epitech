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

void add_tower(char **data, struct tower **t)
{
    struct tower *element;
    element = malloc(sizeof(*element));
    element->x = my_str_to_int( data[1]);
    element->y = my_str_to_int( data[2]);
    float radius = my_str_to_int( data[3]);
    radius = (radius / 100) * 1980;
    element->radius = radius;
    element->circ = create_circle(element->radius, 0, 0);
    element->next = *t;
    *t = element;
    return;
}

void add_aircraft(char **data, struct aircraft **a)
{
    struct aircraft *element;
    element = malloc(sizeof(*element));
    element->x = my_str_to_int( data[1]);
    element->y = my_str_to_int( data[2]);
    element->x_arrival = my_str_to_int( data[3]);
    element->y_arrival = my_str_to_int( data[4]);
    element->vector = get_vector(element->x, element->y,
    element->x_arrival, element->y_arrival);
    element->speed = my_str_to_int( data[5]);
    element->delay = my_str_to_int( data[6]);
    element->status = 0;
    which_pokemon(element);
    element->next = *a;
    element->prev = NULL;
    if (*a) (*a)->prev = element;
    (*a) = element;
}

static int is_tower_data_invalid(char **data, struct tower **t)
{
    if (my_array_len(data) != 4) return 84;
    add_tower(data, t);
    return 1;
}

static int is_aircraft_data_invalid(char **data,
struct aircraft **a)
{
    if (my_array_len(data) != 7) return 84;
    add_aircraft(data, a);
    return 0;
}

int add_new_data(struct aircraft **a, struct tower **t, char **data)
{
    if (data[0][0] == 'T') {
        is_tower_data_invalid(data, t);
    } else {
        is_aircraft_data_invalid(data, a);
    }
    return 1;
}
