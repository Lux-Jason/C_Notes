#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void SetMine(char board[ROWS][COLS], int row, int col);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void CheckMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

