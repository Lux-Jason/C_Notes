/*
=============================================
 Name: A4T4T330026132.c
 Author: Qiao Yichang
 Version:
 Copyright: Your copyright notice
 Description: 
 ============================================= */
#include <stdio.h>

struct Student {
    char name[20];
    char ID[10];
    int score;
};

int main() {
    FILE *file = fopen("stuScore.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct Student student;
	int count =0;
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        printf("%s %s %d\n", student.name, student.ID, student.score);
		count++;
    }
	printf("Totally there are %d students' records in this file\n",count);

    fclose(file);
    return 0;
}

