/*
=============================================
 Name: L10T1T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>

int main() 
{
	char str[50];
	int count = 0;
	
	printf("Input a string: ");
	fgets(str, sizeof(str), stdin);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'a')
		{
			count++;
		}
	}

	printf("There totally %d 'a' in %s\n", count, str);

	return 0;
}
