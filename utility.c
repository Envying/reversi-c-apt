/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : JONATHAN SUN
 * Student Number   : S3432733
 * Course Code      : COSC1076
 * Program Code     : BP094
 * File Name        : utility.c
 * Start up code provided by ... SHAAHIN MADANI
 **********************************************************************/

#include "utility.h"
/**
 * Function required to be used when clearing the buffer. It simply reads
 * each char from the buffer until the buffer is empty again. Please refer
 * to the materials on string and buffer handling in the course for more
 * information.
 **/
void readRestOfLine()
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != '\n')
    { } /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr(stdin);
}
