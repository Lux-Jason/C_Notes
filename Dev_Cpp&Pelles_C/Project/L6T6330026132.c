/*
=============================================
 Name: L6T6T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
/*#include<stdio.h>
int main()
{
	int n = 0;
	int sum = 0;
	printf("Input a positive integer: ");
	scanf("%d", &n);
	if (0 < n)
	{
		for (int i = 1; i <= n; i++)
		{
			if ((0 == i % 5) && (0 != i % 7))
			{
				sum += i;
				if (5 < (n - i)&&0 != ((i+5)%7))
				{
					printf("%d + ", i);

				}
				else if (10<(n-i))
				{
					printf("%d + ", i);
				}
				else
				{
					printf("%d = %d\n", i, sum);
				}
			}
		}

	}
	else
	{
		printf("Warning! You should input a positive integer.\n");
	}
	return 0;
}
