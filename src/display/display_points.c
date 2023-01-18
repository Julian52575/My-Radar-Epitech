/*
** EPITECH PROJECT, 2022
** chained colision
** File description:
** check the colisions and do stuff
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

//p1 is rect, p2 is circ
void display_points_proches(sfVector2f p1, sfVector2f p2,
struct csfml_tools *ct, struct my_radar *mr)
{
    if (mr->p_button % 2 == 0) return;
    sfVector2f p1_pos = p1;
    p1_pos.y -= 2;
    p1_pos.y -= 2;
    sfSprite_setPosition(mr->r_point, p2);
    sfRenderWindow_drawSprite(ct->window, mr->r_point, NULL);
    sfSprite_setPosition(mr->c_point, p1_pos);
    sfRenderWindow_drawSprite(ct->window, mr->c_point, NULL);
}

void display_points_proches_p(sfVector2f p1, sfVector2f p2,
struct csfml_tools *ct, struct my_radar *mr)
{
    if (mr->p_button % 2 == 0) return;
    sfVector2f p1_pos = p1;
    p1_pos.y -= 2;
    p1_pos.y -= 2;
    sfSprite_setPosition(mr->r_point, p2);
    sfRenderWindow_drawSprite(ct->window, mr->r_point, NULL);
    sfSprite_setPosition(mr->c_point, p1_pos);
    sfRenderWindow_drawSprite(ct->window, mr->p_point, NULL);
}
