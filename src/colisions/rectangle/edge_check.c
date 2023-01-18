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
static int top_left_edge_colision(sfRectangleShape *rect1,
sfRectangleShape *rect2);
static int top_right_edge_colision(sfRectangleShape *rect1,
sfRectangleShape *rect2);
static int bottom_right_edge_colision(sfRectangleShape *rect1,
sfRectangleShape *rect2);
static int bottom_left_edge_colision(sfRectangleShape *rect1,
sfRectangleShape *rect2);

int all_edge_colision(sfRectangleShape *rect1, sfRectangleShape *rect2)
{
    if (top_left_edge_colision(rect1, rect2) == 1) return 1;
    if (top_right_edge_colision(rect1, rect2) == 1) return 1;
    if (bottom_right_edge_colision(rect1, rect2) == 1) return 1;
    if (bottom_left_edge_colision(rect1, rect2) == 1) return 1;

    if (top_left_edge_colision(rect2, rect1) == 1) return 1;
    if (top_right_edge_colision(rect2, rect1) == 1) return 1;
    if (bottom_right_edge_colision(rect2, rect1) == 1) return 1;
    if (bottom_left_edge_colision(rect2, rect1) == 1) return 1;
    return 0;
}

static int top_left_edge_colision(sfRectangleShape *rect1,
sfRectangleShape *rect2)
{
    sfVector2f point = sfRectangleShape_getPosition(rect1);
    sfVector2f rectangle2 = sfRectangleShape_getPosition(rect2);

    if (rectangle2.x <= point.x
    && point.x <= (rectangle2.x + sfRectangleShape_getSize(rect2).x) ) {
        if (rectangle2.y <= point.y
        && point.y <= (rectangle2.y + sfRectangleShape_getSize(rect2).y) ) {
            return 1;
        }
    }
    return 0;
}

static int top_right_edge_colision(sfRectangleShape *rect1,
sfRectangleShape *rect2)
{
    sfVector2f point = sfRectangleShape_getPosition(rect1);
    sfVector2f rectangle2 = sfRectangleShape_getPosition(rect2);
    point.x += sfRectangleShape_getSize(rect1).x;

    if (rectangle2.x <= point.x
    && point.x <= (rectangle2.x + sfRectangleShape_getSize(rect2).x) ) {
        if (rectangle2.y <= point.y
        && point.y <= (rectangle2.y + sfRectangleShape_getSize(rect2).y) ) {
            return 1;
        }
    }
    return 0;
}

static int bottom_right_edge_colision(sfRectangleShape *rect1,
sfRectangleShape *rect2)
{
    sfVector2f point = sfRectangleShape_getPosition(rect1);
    sfVector2f rectangle2 = sfRectangleShape_getPosition(rect2);
    point.x += sfRectangleShape_getSize(rect1).x;
    point.y += sfRectangleShape_getSize(rect1).y;
    if (rectangle2.x <= point.x
    && point.x <= (rectangle2.x + sfRectangleShape_getSize(rect2).x) ) {
        if (rectangle2.y <= point.y
        && point.y <= (rectangle2.y + sfRectangleShape_getSize(rect2).y) ) {
            return 1;
        }
    }
    return 0;
}

static int bottom_left_edge_colision(sfRectangleShape *rect1,
sfRectangleShape *rect2)
{
    sfVector2f point = sfRectangleShape_getPosition(rect1);
    sfVector2f rectangle2 = sfRectangleShape_getPosition(rect2);
    point.y += sfRectangleShape_getSize(rect1).y;
    if (rectangle2.x <= point.x
    && point.x <= (rectangle2.x + sfRectangleShape_getSize(rect2).x) ) {
        if (rectangle2.y <= point.y
        && point.y <= (rectangle2.y + sfRectangleShape_getSize(rect2).y) ) {
            return 1;
        }
    }
    return 0;
}
