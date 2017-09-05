/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : JONATHAN SUN
 * Student Number   : S3432733
 * Course Code      : COSC1076
 * Program Code     : BP094
 * File Name        : gameboard.c
 * Start up code provided by ... SHAAHIN MADANI
 **********************************************************************/

#include "gameboard.h"

  int x, y;

void initBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
  /* an array is created for the board*/
  for (y = 0; y < BOARD_HEIGHT; y++)
  {
    for (x = 0; x < BOARD_WIDTH; x++)
    {
      /* pre setting the intial positions of the 4 pieces on the board, all other positions are blank*/
      if ((x == 4 && y == 4) || (x == 5 && y == 5))
      {
        board[y][x] = RED;
      }
      else if((y == 4 && x == 5) || (y == 5 && x == 4))
      {
        board[y][x] = CYAN;
      }
      else
      {
        board[y][x] = BLANK;
      }
    }
  }
}

void displayBoard(
    Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * first, Player * second)
{
  int z = 7;
  int i = 1;

  for (x = 0; x < BOARD_WIDTH + 4; x++)
  {
    printf("====");
  }
  printf("\n");
  printf("Player One's Details \n");
  for (x = 0; x < BOARD_WIDTH - 2; x++)
  {
    printf("----");
  }
  printf("\n");
  printf("Name: %s   Score: %d   Token Colour: ", first->name, first->score);
  if (first->token == RED)
  {
    printf(COLOR_RED "O" COLOR_RESET);
  }
  else
  {
    printf(COLOR_CYAN "O" COLOR_RESET);
  }
  printf("\n");
  for (x = 0; x < BOARD_WIDTH + 4; x++)
  {
    printf("----");
  }
  printf("\n");

  printf("Player Two's Details \n");
  for (x = 0; x < BOARD_WIDTH - 2; x++)
  {
    printf("----");
  }
  printf("\n");
  printf("Name: %s   Score: %d   Token Colour: ", second->name, second->score);
  if (second->token == RED)
  {
    printf(COLOR_RED "O" COLOR_RESET);
  }
  else
  {
    printf(COLOR_CYAN "O" COLOR_RESET);
  }
  printf("\n");
  for (x = 0; x < BOARD_WIDTH + 4; x++)
  {
    printf("====");
  }
  printf("\n");

  printf("    ");
  for (y = 0; y < BOARD_HEIGHT + 1; y++)
  {
    if (z < BOARD_HEIGHT)
    {
      for (x = 0; x <= BOARD_WIDTH - 1; x++)
      {
        printf(" %d  ", x + 1);
      }
      printf("\n");
      for (x = 0; x < BOARD_WIDTH + 1; x++)
      {
        printf("====");
      }
      printf("\n");
      z++;
    }
    else
    {
      for (x = 0; x < BOARD_WIDTH + 1; x++)
      {
        if (x == 0)
        {
          printf (" %d ", y);
        }
        else if (x == 8)
        {
          if (board[y][x] == RED)
          {
            printf("|" COLOR_RED " O " COLOR_RESET "|");
          }
          else if(board[y][x] == CYAN)
          {
            printf("|" COLOR_CYAN " O " COLOR_RESET "|");
          }
          else
          {
          printf (COLOR_RESET"|   |" COLOR_RESET);
          }
        }
        else
        {
          if (board[y][x] == RED)
          {
            printf("|" COLOR_RED " O " COLOR_RESET);
          }
          else if(board[y][x] == CYAN)
          {
            printf("|" COLOR_CYAN " O " COLOR_RESET);
          }
          else
          {
            printf(COLOR_RESET "|   " COLOR_RESET );
          }
        }
      }
      printf("\n");
      if (i < BOARD_HEIGHT)
      {
        for (x = 0; x < BOARD_WIDTH + 1; x++)
        {
          printf("----");
        }
      }
      else
      {
        for (x = 0; x < BOARD_WIDTH + 1; x++)
        {
          printf("====");
        }
      }
      i++;
      printf("\n");
    }
  }
}
