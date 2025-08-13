

#include"head.h"

void savefile() {
	FILE* file;
	int i, j, k;
	file = fopen("file.txt","w+");
	if (file != NULL) {
		for (i = 0; i < num_Courses; i++) {
			fprintf(file, "%s %s %.2f %d", Course_arr[i].courseID, Course_arr[i].coursename, Course_arr[i].Final, Course_arr[i].data);
			fprintf(file, "\n");
			for (j = 0; j < Course_arr[i].data; j++) {
				fprintf(file, "%s %.2f %.2f %d", Course_arr[i].item[j].name, Course_arr[i].item[j].percentage, Course_arr[i].item[j].maxScore, Course_arr[i].item[j].numOfGrades);
				for (k = 0; k < Course_arr[i].item[j].numOfGrades; k++)
				{
					fprintf(file, " %.2f", Course_arr[i].item[j].grades[k]);
				}
				fprintf(file, "\n");
			}
			fprintf(file, "\n");
		}
		fclose(file);
		printf("Data written to file successfully.\n");
	}
	else
		printf("Error opening file for writing.\n");
}
int charToInt(char c)
{
	switch (c) 
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		return -1;
	}
}
int main()
{
	FILE* pf;
	while (1)
	{
		int choice = MainMenu();
		switch (choice)
		{
		case 1: // Edit Course
			EditCourse();
			break;
		case 2: // Edit Grade 
			EditGrade();
			break;
		case 3: // Expected Final Grade
			ExpectedFinalGrade();
			break;
		case 4: // View Course
			ViewCourse();
			break;
		case 5: // Exit
			savefile();
			printf("Exit programme\n");
			return 0;
		default:
			break;
		}
	}
	return 0;
}
