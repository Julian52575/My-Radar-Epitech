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

void display_aircraft(struct my_radar *mr, struct csfml_tools *ct)
{
    sfVector2f a_pos = {mr->a->x_arrival, mr->a->y_arrival};
    sfRectangleShape_setPosition(mr->a->rect, a_pos);
    if (mr->a_button % 2 == 0 && mr->a->status == 0 &&
    mr->a->delay < ct->time_buffer )
        sfRenderWindow_drawRectangleShape(ct->window, mr->a->rect, NULL);
    sfVector2f pos = {mr->a->x, mr->a->y};
    sfRectangleShape_setPosition(mr->a->rect, pos);
    if (mr->s_button % 2 == 0 && mr->a->status == 0 &&
    mr->a->delay < ct->time_buffer ) {
        sfSprite_setPosition(mr->TableauS[mr->a->id], pos);
        sfRenderWindow_drawSprite(ct->window, mr->TableauS[mr->a->id], NULL);
    }
    if (mr->l_button % 2 == 0 && mr->a->status == 0
    && mr->a->delay < ct->time_buffer) {
        sfRenderWindow_drawRectangleShape(ct->window, mr->a->rect, NULL);
    }
}
