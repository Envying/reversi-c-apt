/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : JONATHAN SUN
 * Student Number   : S3432733
 * Course Code      : COSC1076
 * Program Code     : BP094
 * File Name        : utility.h
 * Start up code provided by ... SHAAHIN MADANI
 **********************************************************************/

#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef enum boolean
{
    FALSE = 0,
    TRUE
} Boolean;

#define NEW_LINE_SPACE 1
#define NULL_SPACE 1

/**
 * This is used to compensate for the extra character spaces taken up by
 * the '\n' and '\0' when input is read through fgets().
 **/
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)

#define EMPTY_STRING ""

/**
 * Call this function whenever you detect buffer overflow.
 **/
void readRestOfLine();
void playerNameInput();

#endif
