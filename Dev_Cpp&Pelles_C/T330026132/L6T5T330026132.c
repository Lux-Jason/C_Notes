/*
=============================================
 Name: L6T5T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
/*#include<stdio.h>
const int total_courses = 6;

int main()
{
	int total_units = 0;
	int total_grade = 0;
	int grade = 0;
	for (int i = 1; i <= total_courses * 2; i++)
	{

		if (i == 1)
			printf("Please input grade and units for each course (6 courses):");
		int tmp = getchar() - '0';



		if (i % 2 == 1)
		{
			if (tmp < 17 || tmp > 22 || tmp == 21)
			{
				printf("Warning! Invalid grade.");
				break;
			}
			else
			{
				if (tmp >= 17 && tmp <= 20)
					tmp = 21 - tmp;
				else
					tmp = 0;
			}
			grade = tmp;
		}

		if (i % 2 == 0)
		{
			if (tmp != 1 && tmp != 3)
			{
				printf("Warning! Invalid grade.");
				break;
			}
			total_units = total_units + tmp * 1;
			total_grade = total_grade + tmp * grade;

		}
		getchar();
		if (i==total_courses*2)
		{
			double GPA = 0;
			GPA = (double)total_grade / (double)total_units;

			printf("The GPA for this semester is : %.2f\n", GPA);
		}
	}
	return 0;
}
