/*
=============================================
 Name: L11T4T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
enum year { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
int main()
{
	int i;
	for (i = Jan; i <= Dec; i++)
	{
		printf("%d ", i);
	}
	return 0;
}
