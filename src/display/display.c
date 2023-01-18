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

static void display_air(struct my_radar *mr, struct csfml_tools *ct)
{
    struct aircraft *tmp = mr->a;
    while (mr->a) {
        if (mr->a->status == 0) {
            display_aircraft(mr, ct);
        }
        mr->a = mr->a->next;
    }
    mr->a = tmp;
    return;
}

static void display_tow(struct my_radar *mr, struct csfml_tools *ct)
{
    struct tower *tmp = mr->t;
    while (mr->t) {
        display_tower(mr, ct);
        mr->t = mr->t->next;
    }
    mr->t = tmp;
    return;
}

void display(struct my_radar *mr, struct csfml_tools *ct)
{
    display_tow(mr, ct);
    display_air(mr, ct);
    display_pikachu(mr, ct);
    int c = ct->time_buffer;
    sfText_setString(mr->timer, my_int_to_str(c) );
    sfRenderWindow_drawText(ct->window, mr->timer, NULL);
    int a = mr->game_speed;
    if (a < 1) a = 0;
    sfText_setString(mr->txt_speed, my_int_to_str(a));
    sfRenderWindow_drawText(ct->window, mr->txt_speed, NULL);
}
