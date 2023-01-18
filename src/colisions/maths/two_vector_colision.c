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
#include "my.h"

//V needs to be smaller to trigger an colision
int two_vector_colision(sfVector2f v, sfVector2f u)
{
    int totalV = my_abs_float(v.x) + my_abs_float(v.y);
    int totalU = my_abs_float(u.x) + my_abs_float(u.y);
    if (totalV <= totalU) return 1;
    return 0;
}
