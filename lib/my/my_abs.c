/*
** EPITECH PROJECT, 2022
** produit scalaire
** File description:
** produit scalaire
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

float my_abs_float(float i)
{
    if (i < 0.00) i *= -1;
    return i;
}
