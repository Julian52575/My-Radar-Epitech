/*
** EPITECH PROJECT, 2022
** add new data
** File description:
** get the data from the .rdr file
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include "my_csfml.h"
#include "my_radar.h"
#include "my.h"

static int random_pokemon(struct aircraft *element)
{
    srand(time(NULL));
    int r = rand() * (long int)(&element);
    r = abs(r);
    if (r % 10000 == 8) {
        return 2;
    }
    if (4 < (r % 10) && (r % 10) < 7) return 1;
    if (r % 10 == 8) {
        return 3;
    }
    return 0;
}

void which_pokemon(struct aircraft *element)
{
    int p = random_pokemon(element);
    element->id = p;
    if (p == 2) {
        element->rect = create_rectangle(44, 49, 0, 0);
        sfRectangleShape_setOutlineColor(element->rect, sfRed);
    }
    if (p == 1) {
        element->rect = create_rectangle(17, 9, 0, 0);
        sfColor c = sfColor_fromRGB(62, 74, 79);
        sfRectangleShape_setOutlineColor(element->rect, c);
    }
    if (p == 0) {
        element->rect = create_rectangle(20, 20, 0, 0);
        sfRectangleShape_setOutlineColor(element->rect, sfGreen);
    }
    if (p == 3) {
        element->rect = create_rectangle(15, 24, 0, 0);
        sfRectangleShape_setOutlineColor(element->rect, sfWhite);
    }
}
