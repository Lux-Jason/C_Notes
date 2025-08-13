/*
=============================================
 Name: L7T3T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
/*#include<stdio.h>
#include<malloc.h>
int main()
{
	int n = 0;
	printf("Input the total number of letters: ");
	scanf("%d", &n);
	char* ch = (char*)malloc(sizeof(int) * n);
	if (n<0)
	{
		printf("Warning! Total number should be a positive integer!\n");
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (0 == i)
			{
				printf("Input %d ASCII codes: ",n);
			}
			scanf("%d", &ch[i]);
			if (ch[i] < 65 || ch[i] > 122 || (ch[i] > 90 && ch[i] < 97))
			{
				printf("Warning! Invalid ASCII code.\n");
				break;
			}
			if(i==n-1)
			{
				printf("%s\n", ch);
			}

		}
	}
	free(ch);
	return 0;
}
