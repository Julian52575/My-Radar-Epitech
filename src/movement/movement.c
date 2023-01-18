/*
** EPITECH PROJECT, 2022
** game loop
** File description:
** ~ ~
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdio.h>
#include "my_csfml.h"
#include "my_radar.h"
#include "my.h"

static int aircraft_landed(struct my_radar *mr)
{
    int a = 0;
    if (mr->a->vector.x > 0) {
        if (mr->a->x > mr->a->x_arrival) ++a;
    } else {
        if (mr->a->x <= mr->a->x_arrival) ++a;
    }
    if (mr->a->vector.y > 0) {
        if (mr->a->y > mr->a->y_arrival) ++a;
    } else {
        if (mr->a->y <= mr->a->y_arrival) ++a;
    }
    return a;
}

static sfVector2f get_percentage_vector(struct my_radar *mr)
{
    float x = mr->a->vector.x;
    float y = mr->a->vector.y;
    float total = my_abs_float(x) + my_abs_float(y);
    sfVector2f v = {0, 0};
    v.x = x / total;
    v.y = y / total;
    return v;
}

void mouvement(struct my_radar *mr, struct csfml_tools *ct)
{
    struct aircraft *tmp = mr->a;
    while (mr->a) {
        if (mr->a->status != 0 || mr->a->delay > ct->time_buffer) {
            mr->a = mr->a->next;
            continue;
        }
        if (aircraft_landed(mr) == 2) {
            remove_airplane(mr, mr->a, 1);
            mr->a = mr->a->next;
            continue;
        }
        sfVector2f v = get_percentage_vector(mr);
        mr->a->x += ( (mr->a->speed / (1 / 0.02) ) * v.x) * mr->game_speed;
        mr->a->y += ( (mr->a->speed / (1 / 0.02) ) * v.y) * mr->game_speed;
        mr->a = mr->a->next;
    }
    mr->a = tmp;
}
