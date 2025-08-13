//所有对课程操作的子程序所在文件
#include"head.h"
int num_Courses = 0;
int num_Item = 0;


void EditCourse()
{
	int choice;
	do
	{
		choice = EditCourse_Menu();
		switch (choice)
		{
		case 1: // Add Course
			AddCourse();
			break;
		case 2: // Delete Course
			DeleteCourse();
			break;
		case 3: // Delete All Courses
			DeleteAllCourses();
			break;
		case 4: // Modify Course
			ModifyCourse();
			break;
		case 5:
			break;
		default:
			printf("Illegal operating,please choose again\n");
			break;
		}
	} while (choice != 5);

}

void ViewCourse() 
{
	printf("There're totally %d courses recorded:\n", num_Courses);
	for (int i = 0; i < num_Courses; ++i)
	{
		printf("\n\t| %-7d | %-20s | %-11s |\n", i + 1, Course_arr[i].courseID, Course_arr[i].coursename);
	}
	while(1)
	{
		printf("Enter a number to view the related course details or enter any other key back:");
		int choice_v;
		scanf("%d", &choice_v);
		if (choice_v > 0 && choice_v <= num_Courses)
		{
			printf("\t%s %s\n", Course_arr[choice_v - 1].courseID, Course_arr[choice_v - 1].coursename);
			printf("\t-----------------------------------\n");
			printf("\t| No.    | Item                 | Percentage | Full Mark  | Grades\n");

			int itemcode = 0;
			while (itemcode < Course_arr[choice_v - 1].data)
			{
				printf("\t| %-7d| %-21s| %-11f| %-11f|", itemcode, Course_arr[choice_v - 1].item[itemcode].name, Course_arr[choice_v - 1].item[itemcode].percentage, Course_arr[choice_v - 1].item[itemcode].maxScore);
				int gradescode = 0;
				for (int p = 0; p < (Course_arr[choice_v - 1].item[itemcode].numOfGrades); p++)
				{
					printf(" %d: %.2f ", gradescode + 1, Course_arr[choice_v - 1].item[itemcode].grades[gradescode]);
					if (gradescode % 5 == 0)
					{
						printf("\t|        |                      |            |            |");
					}
				}
				printf("\n");
				itemcode++;
			}
			printf("\t-----------------------------------\n");

			printf("There're totally %d courses recorded:\n", num_Courses);
			for (int i = 0; i < num_Courses; ++i)
			{
				printf("\n\t| %-7d | %-20s | %-11s |\n", i + 1, Course_arr[i].courseID, Course_arr[i].coursename);
			}
		}
		else
		{
			return;
		}
	}
}

void AddCourse()
{
	while (1)
	{

		printf("There're totally %d courses recorded:\n\n", num_Courses);
		int len = strlen(Course_arr);
		if (num_Courses!=0)
		{
			for (int i = 0; i < num_Courses; ++i)
			{
				printf("\t| %-7d | %-20s | %-11s |\n", i + 1, Course_arr[i].courseID, Course_arr[i].coursename);
			}
		}
		if (num_Courses >= MAX_COURSE)
		{
			return;
		}
		Course new_Course;
		printf("Enter NEW course ID (Character+Number, lenghth < 10) or any single key back:");
		char ch1[10];
		getchar();
		gets(ch1);
		int len1 = strlen(ch1);
		if (len1 > 1)
		{
			strcpy(new_Course.courseID, ch1);
			for (int i = 0; i <= num_Courses; i++)
			{
				if (strcmp(Course_arr[i].courseID, new_Course.courseID) == 0)
				{
					printf("Duplicate ID, please input again!\n");
					return;
				}
			}
			printf("Enter course name (less than 50 characters with spaces):");
			char ch2[50];
			gets(ch2);
			int len2 = strlen(ch2);
			if (len2 > 1)
			{
				strcpy(new_Course.coursename, ch2);
				for (int i = 0; i <= num_Courses; i++)
				{
					if (strcmp(Course_arr[i].coursename, new_Course.coursename) == 0)
					{
						printf("Duplicate name, please input again!\n");
						return;
					}
				}
				printf("Add course successfully but evaluation items.\n\n");
				printf("The newly added course is %s, %s.\n", new_Course.courseID, new_Course.coursename);
				Course_arr[num_Courses] = new_Course;
				
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
		char m;
		printf("\nContinue to set the evaluation items for this course? (Y or y: yes; any other character: no):");
		scanf("%c", &m);
		if (m == 'Y' || m == 'y')
		{
			int m = 0;
			printf("Enter number of evaluation items for the new course:");
			scanf("%d", &m);
			printf("Input name, percentage, full marks for each item\n");
			printf("(attention: no space in names and the total percentage should be 100):");
			Course_arr[num_Courses].data = 0;
			for (int i = 0; i < m; i++)
			{
				scanf("%s %f %f", &Course_arr[num_Courses].item[i].name, &Course_arr[num_Courses].item[i].percentage, &Course_arr[num_Courses].item[i].maxScore);
				Course_arr[num_Courses].item[i].numOfGrades = 0;
				Course_arr[num_Courses].data++;
			}
			num_Courses++;
		}
		else
		{
			break;
		}
	}
}
void DeleteCourse()
{
	while (1)
	{
		if (num_Courses!=0)
		{
			printf("There're totally %d courses recorded:\n", num_Courses);
			for (int i = 0; i < num_Courses; ++i)
			{
				printf("\t| %-7d | %-20s | %-11s |\n", i + 1, Course_arr[i].courseID, Course_arr[i].coursename);
			}
			int i = 0;
			char o = 0;
			printf("Enter a number to delete the related course or any other key back: ");
			scanf("%d", &i);
			if (i>0&&i<=num_Courses)
			{
				for (; i < num_Courses; i++)
				{
					for (int j = i - 1; j < num_Courses; j++)
					{
						strcpy(Course_arr[i - 1].courseID, Course_arr[i].courseID);
						strcpy(Course_arr[i - 1].coursename, Course_arr[i].coursename);
						Course_arr[i - 1].data = Course_arr[i].data;
						for (int s = 0; s < MAX_ITEM; s++)
						{
							for (int p = 0; p < MAX_ITEM_GRADES; p++)
							{
								Course_arr[i - 1].item[s].grades[p] = Course_arr[i].item[s].grades[p];
							}
							strcpy(Course_arr[i - 1].item[s].name, Course_arr[i].item[s].name);
							Course_arr[i - 1].item[s].maxScore = Course_arr[i].item[s].maxScore;
							Course_arr[i - 1].item[s].numOfGrades = Course_arr[i].item[s].numOfGrades;
							Course_arr[i - 1].item[s].percentage = Course_arr[i].item[s].percentage;

						}
					}
				}
				
				num_Courses--;
			}
			else
			{
				return;
			}

		}
		else
		{
			return;
		}
	}
		
}
void DeleteAllCourses()
{
	memset(Course_arr, '/0', sizeof(Course_arr));
	num_Courses = 0;
}
void ModifyCourse()
{
	int m = 0;
	int n = 0;
	int choice = 0;

	printf("There're totally %d courses recorded:\n", num_Courses);
	int len = strlen(Course_arr);
	for (int i = 0; i < num_Courses; ++i)
	{
		printf("\n\t| %-7d | %-20s | %-11s |\n", i + 1, Course_arr[i].courseID, Course_arr[i].coursename);
	}
	int i = 0;
	printf("Enter a number to modify the related course details or any other key back: ");
	scanf("%d", &i);
	n = i - 1;

	while (1)
	{

		
		for (int f = 0; f < MAX_ITEM; f++)
		{
			int count = 0;
			for (int l = 0; l < MAX_ITEM_GRADES; l++)
			{
				if (Course_arr[n].item[f].grades[l] >= 0 && Course_arr[n].item[f].grades[l] <= 100)
				{
					count++;
				}
			}
			Course_arr[n].item[f].numOfGrades = count;
		}

		printf("\t%s %s\n", Course_arr[n].courseID, Course_arr[n].coursename);
		printf("\t-----------------------------------\n");
		printf("\t| No.    | Item                 | Percentage | Full Mark  | Grades\n");

		int itemcode = 0;
		while (itemcode < Course_arr[n].data)
		{
			printf("\t| %-7d| %-21s| %-11f| %-11f|", itemcode + 1, Course_arr[n].item[itemcode].name, Course_arr[n].item[itemcode].percentage, Course_arr[n].item[itemcode].maxScore);
			for (int p = 0; p < (Course_arr[n].item[itemcode].numOfGrades); p++)
			{
				printf(" %d: %.2f ", p + 1, Course_arr[n].item[itemcode].grades[p]);
			}
			printf("\n");
			itemcode++;
		}
		printf("\t-----------------------------------\n");
		char choice = 0;
		printf("\n============== Modify Course ==============\n");
		printf("\t1. Modify Course Name\n");
		printf("\t2. Modify Item Name\n");
		printf("\t3. Modify Item Percentage\n");
		printf("\t4. Modify Item Fullmark\n");
		printf("\t5. Add Items If No Item Yet\n");
		printf("============================================\n\n");
		printf("Enter a number to choose an operation or any other key back: ");
		getchar();
		scanf("%c",&choice);
		switch (choice)
		{
		case '1':
			M_Course_name(n);
			break;
		case '2':
			M_Item_name(n);
			break;
		case '3':
			M_Item_percentage(n);
			break;
		case '4':
			M_Item_Fullmark(n);
			break;
		case '5':
			Add_Item_ifnone(n);
			break;
		default:
			return;
		}
	}
	

}
void M_Course_name(int n)
{
	
	printf("You want to change name of course \"%s\" as :", Course_arr[n].coursename);
	getchar();
	gets(Course_arr[n].coursename);
}
void M_Item_name(int n)
{
	int m = 0;
	printf("Enter the No. of an Item to be modified: ");
	scanf("%d", &m);
	printf("Enter a new name:");
	getchar();
	gets(Course_arr[n].item[m-1].name);
}
void M_Item_percentage(int n)
{n;
	printf("Enter the new percentages in order:");
	for (int j = 0; j < Course_arr[n].data; j++)
	{
		scanf("%f ", &Course_arr[n].item[j].percentage);
	}
}
void M_Item_Fullmark(int n)
{
	int i = 0;
	int k = 0;
	printf("Enter the No. of an Item to be modified: ");
	scanf("%d", &i);
	printf("Enter a new fullmark:");
	scanf("%f", &Course_arr[n].item[i-1].maxScore);
}
void Add_Item_ifnone(int n)
{
	if (Course_arr[n].data==0)
	{
		char m;
		printf("\nContinue to set the evaluation items for this course? (Y or y: yes; any other character: no):");
		scanf("%c", &m);
		if (m == 'Y' || m == 'y')
		{
			int m = 0;
			printf("Enter number of evaluation items for the new course:");
			scanf("%d", &m);
			printf("Input name, percentage, full marks for each item\n");
			printf("(attention: no space in names and the total percentage should be 100):");
			Course_arr[n].data = 0;
			for (int i = 0; i < m; i++)
			{
				scanf("%s %f %f", &Course_arr[n].item[i].name, &Course_arr[n].item[i].percentage, &Course_arr[n].item[i].maxScore);
				Course_arr[n].item[i].numOfGrades = 0;
				Course_arr[n].data++;
			}
			num_Courses++;
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
}

