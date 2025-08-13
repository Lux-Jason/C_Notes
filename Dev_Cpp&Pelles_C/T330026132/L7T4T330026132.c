/*
=============================================
 Name: L7T4T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
/*#include <stdio.h>
#include<malloc.h>

void Bubble1(int a[], int n) 
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (a[i] > a[j]) 
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void Bubble2(int a[], int n) 
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (a[i] < a[j]) 
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main()
{
	int n = 0;
	printf("Input the size of the array: ");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	if (0 > n)
	{
		printf("Warning! Array size should be positive.\n");
	}
	else
	{
		int i = 0;
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			if (0==i)
			{
				printf("Input %d integers of the array: ", n);
			}
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (0 == i)
			{
				printf("The original array is: ");
			}
			printf("%d ", arr[i]);
		}
		printf("\n");
		Bubble1(arr, n);
		printf("After sorting, the array in ascending order is: ");
		for (int i = 0; i < n; i++) 
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		Bubble2(arr, n);
		printf("After sorting, the array in descending order is: ");
		for (int i = 0; i < n; i++) 
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	free(arr);
	return 0;
}
