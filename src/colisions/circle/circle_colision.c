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

//Return 1 si colision, 0 sinon
int circle_and_rect_colision(sfRectangleShape *rect, sfCircleShape *circ,
struct csfml_tools *ct, struct my_radar *mr)
{
    sfVector2f perimetre_rect = sfRectangleShape_getSize(rect);
    sfVector2f pos_rect = sfRectangleShape_getPosition(rect);
    float radius_cerc = sfCircleShape_getRadius(circ);
    sfVector2f pos_cerc = sfCircleShape_getPosition(circ);

    sfVector2f centre_cerc = {pos_cerc.x + radius_cerc,
    pos_cerc.y + radius_cerc};
    sfVector2f point_proche_rect =
    get_nearest_point_rect(perimetre_rect, pos_rect, centre_cerc);
    sfVector2f difference_rect = {point_proche_rect.x - centre_cerc.x,
    point_proche_rect.y - centre_cerc.y};
    sfVector2f point_proche_cerc = get_nearest_point_circle(difference_rect,
    centre_cerc, radius_cerc);
    sfVector2f difference_cerc = {point_proche_cerc.x - centre_cerc.x,
    point_proche_cerc.y - centre_cerc.y};
    display_points_proches(point_proche_rect, point_proche_cerc, ct, mr);
    return two_vector_colision(difference_rect, difference_cerc);
}

int circle_and_rect_colision_p(sfRectangleShape *rect, sfCircleShape *circ,
struct csfml_tools *ct, struct my_radar *mr)
{
    sfVector2f perimetre_rect = sfRectangleShape_getSize(rect);
    sfVector2f pos_rect = sfRectangleShape_getPosition(rect);
    float radius_cerc = sfCircleShape_getRadius(circ);
    sfVector2f pos_cerc = sfCircleShape_getPosition(circ);

    sfVector2f centre_cerc = {pos_cerc.x + radius_cerc,
    pos_cerc.y + radius_cerc};
    sfVector2f point_proche_rect =
    get_nearest_point_rect(perimetre_rect, pos_rect, centre_cerc);
    sfVector2f difference_rect = {point_proche_rect.x - centre_cerc.x,
    point_proche_rect.y - centre_cerc.y};
    sfVector2f point_proche_cerc = get_nearest_point_circle(difference_rect,
    centre_cerc, radius_cerc);
    sfVector2f difference_cerc = {point_proche_cerc.x - centre_cerc.x,
    point_proche_cerc.y - centre_cerc.y};
    display_points_proches_p(point_proche_rect, point_proche_cerc, ct, mr);
    return two_vector_colision(difference_rect, difference_cerc);
}

    ///////////////////////////////////////////affichage
    // struct point_proches *pp = malloc( sizeof( struct point_proches* ));
    // pp->p_p_cerc = point_proche_cerc;
    // pp->p_p_rect = point_proche_rect;

// sfVector2f perimetre_rect, sfVector2f pos_rect,
// float radius_cerc, sfVector2f pos_cerc
