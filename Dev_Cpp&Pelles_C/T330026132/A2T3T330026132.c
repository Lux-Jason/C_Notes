/*
=============================================
 Name: A2T3T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
/*#include <stdio.h>
int main() 
{
	int n;
	printf("Input: ");
	scanf("%d", &n);
	printf("Output:\n");
	while(n != 1)
	{
		printf("%d", n);
		if (n % 2 == 0)
		{
			printf("/2=");
			n /= 2;
		}
		else {
			printf("*3+1=");
			n = n * 3 + 1;
		}
		printf("%d\n", n);
	}

	return 0;
}
