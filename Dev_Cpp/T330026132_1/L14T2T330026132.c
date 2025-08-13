/*
=============================================
 Name: L14T2T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;

	printf("Input the number of the data: ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Warning! You should input a positive integer!\n");
	}
	else
	{
		int* data = (int*)malloc(n * sizeof(int));

		printf("Input integer numbers: ");
		for (int i = 0; i < n; ++i) {
			scanf("%d", &data[i]);
		}

		printf("Numbers in reverse order are: ");
		for (int i = n - 1; i >= 0; --i) {
			printf("%d ", data[i]);
		}
		printf("\n");
		free(data);

	}
	return 0;
}
