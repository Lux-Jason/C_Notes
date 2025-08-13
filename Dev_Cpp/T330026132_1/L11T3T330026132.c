/*
=============================================
 Name: L11T3T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stu
{
	char name[50];
	int score;
	char major[50];
};

int cmp_Names(const void* a, const void* b)
{
	return strcmp(((struct Stu*)a)->name, ((struct Stu*)b)->name);
}

int main() 
{
	int numStu;

	printf("Input the number of students: ");
	scanf("%d", &numStu);

	if (numStu <= 0) 
	{
		printf("Warning! Student number should be positive.\n");
		return 0;
	}

	struct Stu* students = (struct Stu*)malloc(numStu * sizeof(struct Stu));

	printf("Please input students' information:\n");
	for (int i = 0; i < numStu; i++) 
	{
		scanf("%s %d %s", students[i].name, &students[i].score, students[i].major);
	}
	qsort(students, numStu, sizeof(struct Stu), cmp_Names);

	printf("The student list in ascending order by name is:\n");
	for (int i = 0; i < numStu; i++) 
	{
		printf("%s %d %s\n", students[i].name, students[i].score, students[i].major);
	}

	free(students);

	return 0;
}
