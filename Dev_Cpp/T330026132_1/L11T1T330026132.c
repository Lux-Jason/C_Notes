/*
=============================================
 Name: L11T1T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
#include <math.h>
#define LINE_LENGTH(x1, y1, x2, y2) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))

struct Point 
{
	float x;
	float y;
};

struct Triangle 
{
	struct Point p1;
	struct Point p2;
	struct Point p3;
};

int main()
{
	struct Triangle triangle;

	printf("Enter the coordinates of the 1st point: ");
	scanf("%f, %f", &triangle.p1.x, &triangle.p1.y);
	printf("Enter the coordinates of the 2nd point: ");
	scanf("%f, %f", &triangle.p2.x, &triangle.p2.y);
	printf("Enter the coordinates of the 3rd point: ");
	scanf("%f, %f", &triangle.p3.x, &triangle.p3.y);

	float l1 = LINE_LENGTH(triangle.p1.x, triangle.p1.y, triangle.p2.x, triangle.p2.y);
	float l2 = LINE_LENGTH(triangle.p2.x, triangle.p2.y, triangle.p3.x, triangle.p3.y);
	float l3 = LINE_LENGTH(triangle.p3.x, triangle.p3.y, triangle.p1.x, triangle.p1.y);

	float circumference = l1 + l2 + l3;
	printf("The circumference of the triangle is %.6f.\n", circumference);

	return 0;
}
