/*
** EPITECH PROJECT, 2022
** main
** File description:
** main for my radar
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

void display_pikachu(struct my_radar *mr, struct csfml_tools *ct)
{
    sfVector2f pos = {mr->x_pikachu, mr->y_pikachu};
    sfRectangleShape_setPosition(mr->pika_rect, pos);
    sfSprite_setPosition(mr->pikachu, pos);
    pos.x -= 1;
    pos.y -= 1;
    sfSprite_setPosition(mr->p_point, pos);
    if (mr->s_button % 2 == 0)
        sfRenderWindow_drawSprite(ct->window, mr->pikachu, NULL);
    if (mr->l_button % 2 == 0)
        sfRenderWindow_drawRectangleShape(ct->window, mr->pika_rect, NULL);
}
