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
#include <math.h>
#include "my_csfml.h"
#include "my_radar.h"

static int which_base_y_sinus(sfVector2f difference)
{
    if (difference.y < 0) return +1;
    return -1;
}

static int which_base_x(sfVector2f difference)
{
    if (difference.x < 0) return -1;
    return +1;
}

//return the nearest point of an circle using the difference vector
sfVector2f get_nearest_point_circle(sfVector2f difference,
sfVector2f centre_cer, float radius)
{
    sfVector2f base = {radius * which_base_x(difference), 0};
    float angle = get_angle(difference, base);
    sfVector2f point_proche_cerc = {
    centre_cer.x + (cosf(angle) * radius * which_base_x(difference)),
    centre_cer.y - (sinf(angle) * radius * which_base_y_sinus(difference)) };
    return point_proche_cerc;
}
