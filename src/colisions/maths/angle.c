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
#include <stdlib.h>
#include "my_csfml.h"
#include <math.h>

float get_angle(sfVector2f vector1, sfVector2f vector2)
{
    float top = produit_scalaire(vector1, vector2, 0);
    float bottom = produit_scalaire(vector1, vector2, 1);
    float cos_angle = top / bottom;
    return acosf(cos_angle);
}
