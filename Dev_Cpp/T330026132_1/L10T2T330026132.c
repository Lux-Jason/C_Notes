/*
=============================================
 Name: L10T2T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
#include<string.h>
int Isupper(char n)
{
	if (n >= 'A' && n <= 'Z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Islower(char n)
{
	if (n >= 'a' && n <= 'z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Isspace(char n)
{
	if (n==' ')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main() 
{
	char str[50];

	printf("Input a string: ");
	fgets(str, sizeof(str), stdin);
	int upper = 0, lower = 0, spaces = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (Isupper(str[i])) 
		{
			upper++;
		}
		else if (Islower(str[i]))
		{
			lower++;
		}
		else if (Isspace(str[i]))
		{
			spaces++;
		}
	}
	for (int i = 0; str[i] == '\n\0'; i++)
	{
		if (str[i] == '\n\0')
		{
			str[i] = '\0';
		}
	}
	str[strlen(str) - 1] = '\0';
	printf("Original str is %s.\n", str);
	printf("There are %d upper-case letters, %d lower-case letters, %d spaces totally.\n", upper, lower, spaces);


	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!Isspace(str[i]))
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';

	printf("String now is %s.\n", str);

	return 0;
}
