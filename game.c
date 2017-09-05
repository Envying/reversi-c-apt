/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : JONATHAN SUN
 * Student Number   : S3432733
 * Course Code      : COSC1076
 * Program Code     : BP094
 * File Name        : game.c
 * Start up code provided by ... SHAAHIN MADANI
 **********************************************************************/

#include "game.h"

char coordinates[COORDLEN], *coords; /* getting the x and y input from player and storing it */
int x, y; /* varibles for the coordinates input by the player*/
int xTest, yTest; /* set to the input by the player and incremented to check for valid Move */
int row, column; /* used to check every direction */
int i;
int score; /* keeping track of the scores for red and cyan tokens */
Boolean validMove = FALSE; /* presetting that validMove is FALSE */


Player * playGame(Player * first, Player * second)
{
  Cell board[BOARD_HEIGHT][BOARD_WIDTH];
  Player * tempPlayerPointer = malloc(sizeof(Player));

  initFirstPlayer(first);
  initSecondPlayer(second,first->token);
  *tempPlayerPointer->name = *second->name;     /* temp storing the second player values*/
  strcpy(tempPlayerPointer->name,second->name); /* compyping the string to tempPlayerPointer */
  initBoard(board);
  displayBoard(board,first,second);
  readRestOfLine();

  /* swaping the players if first player is not red token, so that person who gets red token starts */
  if(first->token != RED)
  {
    swapPlayers(&first,&second);
  }
  /* loops the makeMove, allowing using the quit the game if empty string is enterted */
  while (coordinates[0] != '\n')
  {
    /*MakeMove Returning valse meaning a invalid move has been inputted*/
    if (makeMove(first, board) == FALSE)
    {
      if (coordinates[0] == '\n')
      {
        /* checking if intfirstplayer is second player, if not then swapPlayers then print, then swap back*/
        /* make sure that the second player values dont override the print method in displayBoard*/
        if (strcmp(first->name, tempPlayerPointer->name) == 0)
        {
          swapPlayers(&first,&second);
          gameScore(board,first->token);
          first->score = score;
          gameScore(board,second->token);
          second->score = score;
          displayBoard(board,first,second);
          swapPlayers(&first,&second);
        }
        else
        {
          gameScore(board,first->token);
          first->score = score;
          gameScore(board,second->token);
          second->score = score;
          displayBoard(board,first,second);
        }
      }
      else
      {
        if (strcmp(first->name, tempPlayerPointer->name) == 0)
        {
          swapPlayers(&first,&second);
          gameScore(board,first->token);
          first->score = score;
          gameScore(board,second->token);
          second->score = score;
          displayBoard(board,first,second);
          swapPlayers(&first,&second);
        }
        else
        {
          gameScore(board,first->token);
          first->score = score;
          gameScore(board,second->token);
          second->score = score;
          displayBoard(board,first,second);
        }
        printf("Invalid Move. \n");
      }
    }
    else
    {
      /* valid move has been inputted, therefore apply move will be called to change the tokens*/
      /* checking if intfirstplayer is second player, if not then swapPlayers then print, then swap back*/
      if (applyMove(board,x,y,first->token) == TRUE)
      {
        if (strcmp(first->name, tempPlayerPointer->name) == 0)
        {
          swapPlayers(&first,&second);
          gameScore(board,first->token);
          first->score = score;
          gameScore(board,second->token);
          second->score = score;
          displayBoard(board,first,second);
        }
        else
        {
          gameScore(board,first->token);
          first->score = score;
          gameScore(board,second->token);
          second->score = score;
          displayBoard(board,first,second);
          swapPlayers(&first,&second);
        }
      }
      else
      {
        gameScore(board,first->token);
        first->score = score;
        gameScore(board,second->token);
        second->score = score;
        displayBoard(board,first,second);
        printf("Invalid Move. \n");
      }
    }
  }
  /* when an empty string enters, the game ends therefore score is calculated to see who the winner is*/
  if (coordinates[0] == '\n')
  {
    if (first->score > second->score)
    {
      printf("Winner is %s!!\n", first->name);
    }
    else if (second->score > first->score)
    {
      printf("Winner is %s!!\n", second->name);
    }
    else
    {
      printf("Game ended in a draw!!\n");
    }
  }
  else
  {

  }
  return NULL;
}

Boolean makeMove(Player * player, Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
  const char s[2] = ",";
  char * xToken;
  char * yToken;

  printf("It is %s's turn. \n", player->name);
  printf("Please enter x and y coordiantes seperated by a comma for the piece you wish to place: ");
  fgets(coordinates, sizeof(coordinates), stdin);
  if (coordinates[0] == '\n')
  {
    printf("Exiting \n");
    return FALSE;
  }
  else
  {
    if (coordinates[strlen(coordinates) - 1] != '\n')
    {
      readRestOfLine();
    }
    else
    {
      coordinates[strlen(coordinates) - 1] = '\0';
    }
    /* getting tokens for x and y, to  make sure that x and y have the correct input */
    xToken = strtok(coordinates, s);
    yToken = strtok(NULL, s);
    if (yToken == NULL)
    {
      validMove = FALSE;
    }
    else
    {
      /* turning x and y into integers*/
      x = strtol(xToken, &coords, 0);
      y = strtol(yToken, &coords, 0);
      /* checking whether x and y input or valid from 1-8 or whether the postion placed is a BLANK position */
      if ((x < MIN) || x > MAX || y < MIN || y > MAX || board[y][x] != BLANK)
      {
        validMove = FALSE;
      }
      else
      {
          validMove = FALSE; /* resetting the validMove back to FALSE */
          /* going through the array, of -1 to 1*/
          /* use to add to the y and x values to check the positions on the board */
          for (row = -1; row <= 1; row++)
          {
            for (column = -1; column <= 1; column++)
            {
              /* checking if the next position is out of bounds */
            if ((y + row < 0) || (y + row >= BOARD_HEIGHT) ||
                (x + column < 0) || (x + column >= BOARD_WIDTH) ||
                (row == 0 && column == 0)) /* checking the postion of the piece placed */
              {
                continue;
              }
              if (board[y+row][x+column] == BLANK) /* checking if the next position is a BLANK */
              {
                continue;
              }
              else if (board[y+row][x+column] != player->token) /* checking if the next postion is a CYAN */
              {                                                 /* if next position is CYAN continue to check for Valid Move */
                yTest = y;  /* setting the x and y values to another varaible, so that x and y does not change after incrementing them */
                xTest = x;
                for(i = 0; i < BOARD_HEIGHT;i++)
                {
                  yTest += row;                             /* incrementing the value of y position to check for Valid Move */
                  xTest += column;                          /* incrementing the value of x postion to check for Valid Move */
                  if (xTest < 0 || xTest >= BOARD_WIDTH || yTest < 0 || yTest >= BOARD_HEIGHT) /* if the next position is out of bounds, give up searching for Valid Move */
                  {
                    break;
                  }
                  else if (board[yTest][xTest] == BLANK) /* if the next position is a BLANK, give up searching for Valid Move */
                  {
                    break;
                  }
                  else if (board[yTest][xTest] == player->token) /* if the next position is a RED, a Valid Move has been found */
                  {
                    board[y][x] = player->token;   /* if move is valid, then the intial postion placed becomes the player token colour*/
                    validMove = TRUE;              /* return TRUE that the x,y postion place is Valid */
                    break;
                  }
                  else    /* continue to search until it breaks (meaning that the opposite token is found) */
                  {
                    continue;
                  }
                }
              }
              else
              {
                continue;
              }
            }
          }
      }
    }
  }
  if (validMove == TRUE) /* returning makeMove either TRUE or FALSE depending on whether the move is valid or not */
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

/* apply move has similar method to makeMove, please refer to the comments on makeMove*/
Boolean applyMove(Cell board[BOARD_HEIGHT][BOARD_WIDTH], int x, int y, Cell token)
{
  validMove = FALSE;
  if (token == RED) /* to check whether the player token is RED */
  {
    for (row = -1; row <= 1; row++)
    {
      for (column = -1; column <= 1; column++)
      {
        if ((y + row < 0) || (y + row >= BOARD_HEIGHT) ||
            (x + column < 0) || (x + column >= BOARD_WIDTH) ||
            (row == 0 && column == 0))
        {
          continue;
        }
        if (board[y+row][x+column] == BLANK)
        {
          continue;
        }
        else if(board[y+row][x+column] == CYAN)
        {
          yTest = y;
          xTest = x;
          for(i = 0; i < BOARD_HEIGHT;i++)
          {
            yTest += row;
            xTest += column;
            if (xTest < 0 || xTest >= BOARD_WIDTH || yTest < 0 || yTest >= BOARD_HEIGHT)
            {
              break;
            }
            else if (board[yTest][xTest] == BLANK)
            {
              break;
            }
            else if (board[yTest][xTest] == RED)
            {
              while (board[yTest-=row][xTest-=column] == CYAN) /* if the move is valid turn every move that it went pass by to RED*/
              {
                board[yTest][xTest] = RED;
              }
              validMove = TRUE;
              break;
            }
            else
            {
              continue;
            }
          }
        }
      }
    }
  }
  else /* check for whether the player token is CYAN */
  {
    for (row = -1; row <= 1; row++)
    {
      for (column = -1; column <= 1; column++)
      {
        if ((y + row < 0) || (y + row >= BOARD_HEIGHT) ||
            (x + column < 0) || (x + column >= BOARD_WIDTH) ||
            (row == 0 && column == 0))
        {
          continue;
        }
        if (board[y+row][x+column] == BLANK)
        {
          continue;
        }
        else if(board[y+row][x+column] == RED)
        {
          yTest = y;
          xTest = x;
          for(i = 0; i < BOARD_HEIGHT;i++)
          {
            yTest += row;
            xTest += column;
            if (xTest < 0 || xTest >= BOARD_WIDTH || yTest < 0 || yTest >= BOARD_HEIGHT)
            {
              break;
            }
            else if (board[yTest][xTest] == BLANK)
            {
              break;
            }
            else if (board[yTest][xTest] == CYAN)
            {
              while (board[yTest-=row][xTest-=column] == RED) /* if the move is valid turn every move that it went pass by to CYAN*/
              {
                board[yTest][xTest] = CYAN;
              }
              validMove = TRUE;
              break;
            }
            else
            {
              continue;
            }
          }
        }
      }
    }
  }
  if (validMove == TRUE)
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

unsigned gameScore(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Cell token)
{
  score = 0; /* pre setting the score back to 0 everytime this method is called*/
  if (token == RED)
  {
    for (y = 0; y < BOARD_HEIGHT; y++)
    {
      for (x = 0; x < BOARD_WIDTH; x++)
      {
        if (board[y][x] == RED)
        {
          score++;
        }
      }
    }
  }
  else
  {
    for (y = 0; y < BOARD_HEIGHT; y++)
    {
      for (x = 0; x < BOARD_WIDTH; x++)
      {
        if (board[y][x] == CYAN)
        {
          score++;
        }
      }
    }
  }
  return score;
}

/* swap the player pointers around, making only one pointer being called at a time */
void swapPlayers(Player ** first, Player ** second)
{
  Player *tempP = *first;
  *first = *second;
  *second = tempP;
}
