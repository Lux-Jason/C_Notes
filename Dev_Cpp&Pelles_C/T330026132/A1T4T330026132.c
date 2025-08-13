/*
=============================================
 Name: A1T4T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
/*#include<stdio.h>
int change(char m)
{
	if (m >= 'a' && m <= 'z')
	{
		return m - 'a'+1;
	}
	else if (m >= 'A' && m <= 'Z')
	{
		return m - 'A'+1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char a = ' ';
	char b = ' ';
	printf("Input: ");
	scanf("%c %c", &a, &b);
	int x = change(a);
	int y = change(b);
	if (x != 0 && y != 0)
	{
		if (x < y && x != 0 && y != 0)
		{
			printf("Output: %c %c\n", a, b);
		}
		else if (x > y && x != 0 && y != 0)
		{
			printf("Output: %c %c\n", b, a);
		}
	}
	else if (y == 0 && x != 0)
	{
		printf("Warning! '%c' is not an English letter.\n", b);
	}
	else
	{
		printf("Warning! '%c' is not an English letter.\n", a);
	}
	return 0;
}
