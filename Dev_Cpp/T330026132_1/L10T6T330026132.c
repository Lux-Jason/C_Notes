/*
=============================================
 Name: L10T6T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */

#include <stdio.h>
#include <string.h>
int main() 
{
	char str1[50], str2[50], str3[50];

	printf("Input 3 strings: ");
	scanf("%s %s %s", str1, str2, str3);

	char* position = strstr(str1, str2);

	if (position != NULL) 
	{

		strncpy(position, str3, strlen(str3));
	}
	else 
	{
		strcat(str1, str3);
	}

	printf("Originally, str1 is %s, str2 is %s, str3 is %s.\n", str1, str2, str3);
	printf("now, str1 is %s, str2 is %s, str3 is %s.\n", str1, str2, str3);

	return 0;
}
