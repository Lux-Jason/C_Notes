/*
=============================================
 Name: L10T3T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
#include<assert.h>
char* My_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (*p!='\0')
	{
		s1 = p; s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)p;
		}
		p++;
	}
	return NULL;
}
int main()
{
	char str1[50], str2[50];

	printf("Input 2 strings: ");
	scanf("%s %s", str1, str2);

	char* position = My_strstr(str1, str2);

	if (position)
	{
		printf("str1 contains str2 at position %d\n", position - str1);
	}
	else 
	{
		printf("str1 does not contain str2\n");
	}

	return 0;
}
