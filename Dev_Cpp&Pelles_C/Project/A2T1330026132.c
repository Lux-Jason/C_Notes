/*
=============================================
 Name: A2T1T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
/*#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
 	for ( i = 1; i < 14; i++)
	{
		if (7>=i)
		{
   			if (i % 2 != 0)
			{
				for (int j = i; j > 0; j--)
				{
					printf("#");
				}
				printf("\n");
			}
			else
			{
				for (int j = i; j > 0; j--)
				{
					printf("+");
				}
				printf("\n");
			}
		}
		else
		{
			if (i % 2 != 0)
			{
				for (int j = 13; j >= i; j--)
				{
					printf("#");
				}
				printf("\n");
			}
			else
			{
				for (int j = 13; j >= i; j--)
				{
					printf("+");
				}
				printf("\n");
			}
		}
				
	}
	return 0;
}
