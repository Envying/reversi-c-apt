/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : JONATHAN SUN
 * Student Number   : S3432733
 * Course Code      : COSC1076
 * Program Code     : BP094
 * File Name        : player.h
 * Start up code provided by ... SHAAHIN MADANI
 **********************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "utility.h"


typedef enum cell
{
    BLANK, RED, CYAN
} Cell;

/* Color codes required to display the tokens on the board. */
#define COLOR_RED   "\33[31m"
#define COLOR_CYAN  "\33[36m"
#define COLOR_RESET "\33[0m"

/* The maximum length of a player name. */
#define NAMELEN 20

typedef struct player
{
    char name[NAMELEN + NULL_SPACE];
    Cell token;
    unsigned score;
} Player;

void initFirstPlayer(Player * player);
void initSecondPlayer(Player * player, Cell token);

#endif
