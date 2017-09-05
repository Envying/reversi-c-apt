/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : JONATHAN SUN
 * Student Number   : S3432733
 * Course Code      : COSC1076
 * Program Code     : BP094
 * File Name        : reversi.c
 * Start up code provided by ... SHAAHIN MADANI
 **********************************************************************/

#include "reversi.h"
#include <stdio.h>
#include <stdlib.h>

char userInput[INPUT_VALUE], *endp;
int option;

int main()
{
  /* memory storage use with malloc as well as intialising both player pointers*/
  Player * first = malloc(sizeof(Player));
  Player * second = malloc(sizeof(Player));

  /* do while loop is used to make sure it loops until the player wants to exit the game */
  do {
  printf("Welcome to Reversi! \n"
        "=================== \n"
        "Select an option: \n"
        "1. Play a game \n"
        "2. Quit the Program \n"
        "Please enter your choice: ");

    fgets(userInput, sizeof(userInput), stdin);
      if (userInput[strlen(userInput) - 1] != '\n')
      {
          readRestOfLine();
      }
      else
      {
        userInput[strlen(userInput) - 1] = '\0';
      }
    option = strtol(userInput, &endp, 0);

    switch (option)
    {
      case 1 :
        /* calls the paly game method*/
        playGame(first, second);
        break;
      case 2 :
        /* Exiting the program*/
        printf("Goodbye...... \n\n");
        return EXIT_SUCCESS;
        break;
      default :
        printf("Invalid Option \n");
    }
  } while(option != 2);
    return option;
}
