/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : JONATHAN SUN
 * Student Number   : S3432733
 * Course Code      : COSC1076
 * Program Code     : BP094
 * File Name        : gameboard.h
 * Start up code provided by ... SHAAHIN MADANI
 **********************************************************************/

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "player.h"

#define BOARD_HEIGHT 8
#define BOARD_WIDTH BOARD_HEIGHT

void initBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH]);
void displayBoard(
    Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * first, Player * second);

#endif
