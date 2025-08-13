/*
=============================================
 Name: L11T2T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
#include<stdbool.h>

struct Date
{
	int month;
	int day;
	int year;
};

bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void findNextDay(struct Date* d) 
{
	struct Date nextDay = { 0 };
	if (((d->month == 4 || d->month == 6 || d->month == 9 || d->month == 11) && d->day == 30)||( d->day == 31&&d->month!=12)|| (d->month == 2 && d->day == 29 && isLeapYear(d->year)) || (d->month == 2 && d->day == 28 && !isLeapYear(d->year)))
	{
		nextDay.day = 1;
		nextDay.month = d->month + 1;
		nextDay.year = d->year;
	}
	else if(d->day == 31 && d->month == 12)
	{
		nextDay.day = 1;
		nextDay.month = 1;
		nextDay.year = d->year + 1;
	}
	else
	{
		nextDay.day = d->day + 1;
		nextDay.month = d->month;
		nextDay.year = d->year;
	}
	printf("The next day of input date is %d/%d/%d.\n", nextDay.month, nextDay.day, nextDay.year);
}

int main() 
{
	struct Date currentDate;
	printf("Input a date by the order of month, day, year: ");
	scanf("%d %d %d", &currentDate.month, &currentDate.day, &currentDate.year);

	if (currentDate.year <= 0)
	{
		printf("Warning! Year input should be positive.\n");
	}
	else if (currentDate.month < 1 || currentDate.month > 12)
	{
		printf("Warning! Month input should be ranging in [1, 12].\n");
	}
	else if ((currentDate.day < 1 || currentDate.day > 31)|| (currentDate.month == 2 && currentDate.day > 29)|| (currentDate.month == 2 && currentDate.day == 29 && !isLeapYear(currentDate.year))|| ((currentDate.month == 4 || currentDate.month == 6 || currentDate.month == 9 || currentDate.month == 11) && currentDate.day > 30))
	{
		printf("Warning! Date input is not real.\n");
	}
	else 
	{
		findNextDay(&currentDate);
	}

	return 0;
}
