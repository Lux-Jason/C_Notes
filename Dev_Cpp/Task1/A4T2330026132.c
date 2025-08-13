/*
=============================================
 Name: A4T2T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
#include <string.h>

int occurrence1(char* sub, char* str);
int occurrence2(char* sub, char* str);
int occurrence1(char* sub, char* str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return (strstr(str, sub) == str) + occurrence1(sub, str + 1);
}

int occurrence2(char* sub, char* str)
{
	int count = 0;
	while ((str = strstr(str, sub)) != NULL)
	{
		count++;
		str++;
	}
	return count;
}
int main() 
{
	char str1[20], str2[80];
	printf("Input two strings: ");
	scanf("%s%s", str1, str2);
	printf("Number of occurrences 1: %d\n", occurrence1(str1, str2));
	printf("Number of occurrences 2: %d\n", occurrence2(str1, str2));
	return 0;
}
