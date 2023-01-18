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

void display_tower(struct my_radar *mr, struct csfml_tools *ct)
{
    sfVector2f pos = {mr->t->x, mr->t->y};
    sfSprite_setPosition(mr->t_sprite, pos);
    if (mr->d_button % 2 == 0)
        sfRenderWindow_drawSprite(ct->window, mr->t_sprite, NULL);
    pos.x -= mr->t->radius - 20;
    pos.y -= mr->t->radius - 20;
    sfCircleShape_setPosition(mr->t->circ, pos);
    if (mr->m_button % 2 == 0)
        sfRenderWindow_drawCircleShape(ct->window, mr->t->circ, NULL);
}
