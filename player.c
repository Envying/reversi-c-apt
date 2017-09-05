/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : JONATHAN SUN
 * Student Number   : S3432733
 * Course Code      : COSC1076
 * Program Code     : BP094
 * File Name        : player.c
 * Start up code provided by ... SHAAHIN MADANI
 **********************************************************************/

#include "player.h"

Boolean validName = FALSE; /* to check for a valid name*/

void initFirstPlayer(Player * player)
{
  char player1Name[NAMELEN];
  int colourGenerator;
  do
  {
    printf("Player 1 please enter a username (max %d characters): ", NAMELEN);
    fgets(player1Name, NAMELEN, stdin);
    if (player1Name[strlen(player1Name) - 1] != '\n')
    {
      printf("Name exceed maximum %d characters! \n", NAMELEN);
      readRestOfLine();
    }
    else
    {
      player1Name[strlen(player1Name) - 1] = '\0';
    }
    if (player1Name[0] == '\0') /* not allowing the user to enter a enter string as a name */
    {
      printf("\nInvalid Name... \n\n");
      validName = FALSE;
    }
    else
    {
      strcpy(player->name, player1Name);
      validName = TRUE;
    }
    srand(time(NULL));
    /* random number generator to gerenrate one number either 1 or 2, if player 1 is RED and player 2 is CYAN*/
    colourGenerator = (rand() % 2 ) ;
    if (colourGenerator == 1)
    {
      player->token = RED;
    }
    else
    {
      player->token = CYAN;
    }
  } while(validName != TRUE);
}

void initSecondPlayer(Player * player, Cell token)
{
  char player2Name[NAMELEN];
  do
  {
    printf("Player 2 please enter a username (max %d characters): ", NAMELEN);
    fgets(player2Name, NAMELEN, stdin);
    if (player2Name[strlen(player2Name) - 1] != '\n')
    {
      printf("Name exceed maximum %d characters! \n", NAMELEN);
      readRestOfLine();
    }
    else
    {
      player2Name[strlen(player2Name) - 1] = '\0';
    }
    if (player2Name[0] == '\0') /* not allowing the user to enter a enter string as a name */
    {
      printf("\n Invalid Name... \n\n");
      validName = FALSE;
    }
    else
    {
      strcpy(player->name, player2Name);
      validName = TRUE;
    }
    if (token == RED) /* method to check for a preset token*/
    {
      player->token = CYAN;
    }
    else
    {
      player->token = RED;
    }
  } while (validName != TRUE);
}
