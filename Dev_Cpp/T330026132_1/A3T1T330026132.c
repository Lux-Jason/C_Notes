/*
=============================================
 Name: A3T1T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
#include<assert.h>

#define COL1 3
#define ROW1 3
#define COL2 1
#define ROW2 3

void Mat_mul(double(*arr1)[COL1], double(*arr2)[COL2], double(*arr3)[COL2], int row1, int row2, int col1, int col2)
{
	assert(col1 == row2);
	int i = 0;
	int j = 0;
	int k = 0;
	for ( i = 0; i < row1; i++)
	{
		for (j = 0; j < col2; j++) 
		{
			for ( k = 0; k < col1; k++)
			{
				*(*(arr3 + i) + j) += *(*(arr1 + i) + k) * *(*(arr2 + k) + j);
			}
		}
	}
}
int main()
{
	double arr1[ROW1][COL1] = { {1,2,5},{1,3,1},{0,1,1} };
	double arr2[ROW2][COL2] = { 1,0,1 };
	double arr3[ROW1][COL2] = { 0 };
	Mat_mul(arr1, arr2, arr3, ROW1, ROW2, COL1, COL2);
	for (int i = 0; i < ROW1; i++)
	{
		printf("| ");
		for (int j = 0; j < COL1; j++)
		{
			printf("%.0f ", arr1[i][j]);

		}
		printf("|\n");
	}
	printf("times\n");
	for (int i = 0; i < ROW2; i++)
	{
		printf("| ");
		for (int j = 0; j < COL2; j++)
		{
			printf("%.0f ", arr2[i][j]);
		}
		printf("|\n");
	}
	printf("equal to:\n");
	for (int i = 0; i < ROW1; i++)
	{
		printf("| ");
		for (int j = 0; j < COL2; j++) 
		{
			printf("%.0f ",arr3[i][j]);
		}
		printf("|\n");
	}
	return 0;
}
