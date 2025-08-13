/*
=============================================
 Name: L14T1T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>
#include <stdlib.h>
struct stuRec {
	char name[20];
	int id;
	char gender;
};
int main()
{
	struct stuRec* p;
	p = (struct stuRec*)malloc(sizeof(struct stuRec));
	if (p) {
		printf("please input name, id and gender\n");
		scanf("%s%d%*c%c", p->name, &p->id, &p->gender);
		printf("name:%-10s,ID:%d,gender:%c\n", p->name, p->id, p->gender);
		free(p);
	}
	return 0;
}
/*
1.This program allocates memory to record name, id, and sex of a student, takes input, then prints them.
2.Memory is dynamically allocated using 'malloc'.
3.%*c is used to consume the newline character from the previous input.
4.Changing '%-10s' to '%10s' would right-align the name.
5.free(p) deallocates the dynamically allocated memory.
*/
