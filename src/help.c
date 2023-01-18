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

static void help2(void)
{
    my_putstr("‘+/-‘\taccelerate or slow the in-game timer*\n");
    my_putstr("‘0/9‘\tput the in-game timer to 0 or 9*\n");
    my_putstr("\n*is a bonus\t\t copyright Rulian 2022 epitech nancy\n");
}

int help(void)
{
    my_putstr("Air traffic simulation panel\n\nUSAGE\n ./my_radar [OPTIONS]");
    my_putstr(" path_to_script\n  path_to_script The path to the script file.");
    my_putstr("\n\nOPTIONS\n-h\tprint the usage and quit.\n");
    my_putstr("-g [a] [t] [file_name]\tgenerate a script with ");
    my_putstr("'a' aircrafts and 't' towers inside of 'file_name',\n");
    my_putstr("\ti and j are random if not precised ");
    my_putstr("and the default file path is script.rdr.*\n");
    my_putstr("\nUSER INTERACTIONS\n");
    my_putstr("‘L’\tkey enable/disable aicrafts' hitboxes and areas.\n");
    my_putstr("‘M’\tkey enable/disable towers' hitboxes and areas.\n");
    my_putstr("‘S’\tkey enable/disable aircrafts' sprites.\n");
    my_putstr("‘D’\tkey enable/disable towers' sprites.*\n");
    my_putstr("‘A’\tkey hide/show aicrafts' arrival point.*\n");
    my_putstr("'P'\tShows colisions points of each ");
    my_putstr("circles and aircrafts\n'A'\tShows the arrival point ");
    my_putstr("of each planes*\n");
    my_putstr("‘→‘\tuse the arrow keys to move Pikachu !*\n");
    help2();
    return 0;
}
