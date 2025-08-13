#pragma once
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
//IsWin()告诉我们四种状态：玩家赢(*)/电脑赢(#)/平局(Q)/都没赢(C)
char IsWin(char board[ROW][COL], int row, int col);