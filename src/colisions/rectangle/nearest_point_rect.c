/*
** EPITECH PROJECT, 2022
** main window.c
** File description:
** the main window of an tragedy
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
#include "my.h"
static sfVector2f get_nearest_point_rect2(sfVector2f perimetre_rect,
sfVector2f centre_rect, sfVector2f vecteur_difference);

static sfVector2f get_nearest_point_rect2(sfVector2f perimetre_rect,
sfVector2f centre_rect, sfVector2f v_difference)
{
    sfVector2f point_proche = {centre_rect.x, centre_rect.y};
    if (my_abs_float(v_difference.x) > my_abs_float(perimetre_rect.x / 2) ) {
        if (v_difference.x >= 0)  {
            point_proche.x -= (perimetre_rect.x / 2);
        } else {
            point_proche.x += (perimetre_rect.x / 2);
        }
    } else {
        point_proche.x -= v_difference.x;
    }
    if (my_abs_float(v_difference.y) > my_abs_float(perimetre_rect.y / 2) ) {
        if (v_difference.y >= 0) {
            point_proche.y -= (perimetre_rect.y / 2);
        } else {
            point_proche.y += (perimetre_rect.y / 2);
        }
    } else {
        point_proche.x -= v_difference.x;
    }
    return point_proche;
}

//return the nearest point (to another object) of an rectangle
sfVector2f get_nearest_point_rect(sfVector2f perimetre_rect,
sfVector2f pos_rect, sfVector2f centre_cerc)
{
    sfVector2f centre_rect = {pos_rect.x + (perimetre_rect.x / 2),
    pos_rect.y + (perimetre_rect.y / 2) };
    sfVector2f vecteur_difference = {centre_rect.x - centre_cerc.x,
    centre_rect.y - centre_cerc.y};
    return get_nearest_point_rect2(perimetre_rect,
    centre_rect, vecteur_difference);
}
