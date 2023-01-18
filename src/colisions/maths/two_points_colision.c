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
#include "my_radar.h"

//takes 2 points, an precision for X, an precision for Y and returns 1/0
int two_points_colision(sfVector2f pointA, sfVector2f pointB,
float precisionX, float precisionY)
{
    if ( (pointA.x - precisionX) <= pointB.x
    && pointB.x <= (pointA.x + precisionX) ) {
        if ( (pointA.y - precisionY) <= pointB.y
        && pointB.y <= (pointA.y + precisionY) ) {
            return 1;
        }
    }
    return 0;
}
