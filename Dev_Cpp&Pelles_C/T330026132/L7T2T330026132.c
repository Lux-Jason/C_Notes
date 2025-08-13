/*
=============================================
 Name: L7T2T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */

/*#include<stdio.h>
int main()
{
	int arr[50] = { 0 };
	int n = 0;
	int i = 0; 
	int count = 0;
	printf("Please input a sequence of integers (end with -1): ");
	scanf("%d", &n);
	while (-1 != n)
	{
		arr[i++] = n;
		scanf("%d", &n);
		count++;
	}
	if (0!=count)
	{
		int m = 0;
		printf("Enter the number you want to search:\n");
		scanf("%d", &m);
		for (int j = 0; j <= count; j++)
		{
			if (arr[j] == m)
			{
				printf("The index of %d in the array is %d\n", m, j + 1);
				break;
			}
			if (j == count)
			{
				printf("%d Not found.\n", m);
			}
		}
	}
	else
	{
		printf("Array is empty.\n");
	}

	return 0;
}
