/*
=============================================
 Name: L12T2T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include<stdio.h>
#include<string.h>
struct Student {
	char str[10];
	int marks;
};
int main()
{
	int values[5] = { 5, 10, 15, 20, 22 };
	char str[10], * p;
	int n = 0, i;
	struct Student stu[20], * ps;

	strcpy(str, "UVWXYZ");
	p = str;

	// print the third element in the array values using three different expressions.
	printf("%d %d %d\n", values[2], *(values+2),*( & values[0] +2));
	printf("%c %c\n", str[2], p[2]); //print third char in str through str and p respectively
	printf("%s, %s\n", str, p); //print str string through str and p respectively
	for (i = 0; i < 20; i++) {
		scanf("%s %d", stu[i].str, &stu[i].marks);  // read student's name and marks
		if (stu[i].marks == -1)
			break;
	}
	n = i - 1;
	// with the following two statements, print out the name and marks throught ps
	ps = stu;
	printf("first student\'s name:%s, marks:%d\n", ps->str, ps->marks);
	return 0;
}
