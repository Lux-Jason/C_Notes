#include"head.h"
void EditGrade()
{
	int m = 0;
	int n = 0;
	int choice = 0;
	do
	{
		printf("There're totally %d courses recorded:\n\n", num_Courses);

		for (int i = 0; i < num_Courses; ++i)
		{
			printf("\t| %-7d | %-20s | %-11s |\n", i + 1, Course_arr[i].courseID, Course_arr[i].coursename);
		}
		int i = 0;
		printf("Enter a number to modify the related course details or any other key back: ");
		scanf("%d", &i);
		getchar();
		if (i>0&&i<=num_Courses)
		{
			n = i - 1;

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

			printf("Enter the No. of an Item whose grades to be edited or any other key back: ");
			char j = 0;
			scanf("%c", &j);
			int m = charToInt(j) - 1;
			if (m >= 0 && m < Course_arr[n].data)
			{
				printf("\t%s %s\n", Course_arr[n].courseID, Course_arr[n].coursename);
				printf("\t-----------------------------------\n");
				printf("\t| No.    | Item                 | Percentage | Full Mark  | Grades\n");
				printf("\t| %-7d| %-21s| %-11f| %-11f|", m + 1, Course_arr[n].item[m].name, Course_arr[n].item[m].percentage, Course_arr[n].item[m].maxScore);
				for (int p = 0; p < (Course_arr[n].item[m].numOfGrades); p++)
				{
					printf(" %d: %.2f ", p + 1, Course_arr[n].item[m].grades[p]);
				}
				printf("\n\t-----------------------------------\n");

				choice = EditGrade_Menu();
				switch (choice)
				{
				case 1:
					AddGrade(n, m, Course_arr[n].item[m].numOfGrades);
					break;
				case 2:
					DeleteGrade(n, m, Course_arr[n].item[m].numOfGrades);
					break;
				case 3:
					DeleteAllGrades(n, m, Course_arr[n].item[m].numOfGrades);
					break;
				case 4:
					ModifyGrade(n, m, Course_arr[n].item[m].numOfGrades);
					break;
				case 5:
					break;
				default:
					break;
				}
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
		
	} while (choice != 5);
}
void AddGrade(int n,int m,int count)
{ 
	int i = 0;
	float addn[MAX_ITEM_GRADES];
	Course_arr[n].item[m].numOfGrades = count;
	while (1) 
	{
		printf("Enter a grade to added to the item or a negative number back: ");
		scanf("%f", &addn[i]);
		if (addn[i] < 0) 
		{
			break;
		}
		i++;
		printf("\n");
	}


	for (int l = 0; l < i; l++)
	{
		Course_arr[n].item[m].grades[(Course_arr[n].item[m].numOfGrades)+l] = addn[l];

	}
	Course_arr[n].item[m].numOfGrades += i;
	printf("\t%s %s\n", Course_arr[n].courseID, Course_arr[m].coursename);
	printf("\t-----------------------------------\n");
	printf("\t| No.    | Item                 | Percentage | Full Mark  | Grades\n");
	printf("\t| %-7d| %-21s| %-11f| %-11f|", m + 1, Course_arr[n].item[m].name, Course_arr[n].item[m].percentage, Course_arr[n].item[m].maxScore);
	for (int p = 0; p < Course_arr[n].item[m].numOfGrades; p++)
	{
		printf(" %d: %.2f ", p+1, Course_arr[n].item[m].grades[p]);
	}
	printf("\n\t-----------------------------------\n");

}
void DeleteGrade(int n,int m,int count)
{
	int i = 0;
	Course_arr[n].item[m].numOfGrades = count;
	printf("\t%s %s\n", Course_arr[n].courseID, Course_arr[n].coursename);
	printf("\t-----------------------------------\n");
	printf("\t| No.    | Item                 | Percentage | Full Mark  | Grades\n");
	printf("\t| %-7d| %-21s| %-11f| %-11f|", m+1, Course_arr[n].item[m].name, Course_arr[n].item[m].percentage, Course_arr[n].item[m].maxScore);
	for (int p = 0; p < Course_arr[n].item[m].numOfGrades; p++)
	{
		printf(" %d: %.2f ", p + 1, Course_arr[n].item[m].grades[p]);
	}
	printf("\n\t-----------------------------------\n");
	
	printf("Enter the number of a grade to delete or any other key back: ");
	scanf("%d", &i);
	if (i > 0 && i <= Course_arr[n].item[m].numOfGrades)
	{
		while (i <= Course_arr[n].item[m].numOfGrades)
		{
			Course_arr[n].item[m].grades[i - 1] = Course_arr[n].item[m].grades[i];
			i++;
		}
		Course_arr[n].item[m].numOfGrades--;
	}
}
void DeleteAllGrades(int n,int m,int count)
{
	int i = 0;
	Course_arr[n].item[m].numOfGrades = count;
	while (i <= Course_arr[n].item[m].numOfGrades)
	{
		memset(Course_arr[n].item[m].grades, '\0',sizeof(Course_arr[n].item[m].grades));
		i++;
	}
	Course_arr[n].item[m].numOfGrades = 0;
}



void ModifyGrade(int n,int m, int count)
{
	Course_arr[n].item[m].numOfGrades = count;
	printf("\t%s %s\n", Course_arr[n].courseID, Course_arr[n].coursename);
	printf("\t-----------------------------------\n");
	printf("\t| No.    | Item                 | Percentage | Full Mark  | Grades\n");
	printf("\t| %-7d| %-21s| %-11f| %-11f|", m + 1, Course_arr[n].item[m].name, Course_arr[n].item[m].percentage, Course_arr[n].item[m].maxScore);
	for (int p = 0; p < Course_arr[n].item[m].numOfGrades; p++)
	{
		printf(" %d: %.2f ", p + 1, Course_arr[n].item[m].grades[p]);
	}
	printf("\n\t-----------------------------------\n");

	int i = 0;
	printf("Enter the number of a grade to modify or any other key back: ");
	scanf("%c", &i);
	if (i>=0&&i< Course_arr[n].item[m].numOfGrades)
	{
		printf("You want to change %s Grade %d from %.2f to: ", Course_arr[n].item[m].name, i, Course_arr[n].item[m].grades[i - 1]);
		scanf("%f", &Course_arr[n].item[m].grades[i - 1]);
		printf("\t%s %s\n", Course_arr[n].courseID, Course_arr[n].coursename);
		printf("\t-----------------------------------\n");
		printf("\t| No.    | Item                 | Percentage | Full Mark  | Grades\n");
		printf("\t| %-7d| %-21s| %-11f| %-11f|", m + 1, Course_arr[n].item[m].name, Course_arr[n].item[m].percentage, Course_arr[n].item[m].maxScore);
		for (int p = 0; p < Course_arr[n].item[m].numOfGrades; p++)
		{
			printf(" %d: %.2f ", p + 1, Course_arr[n].item[m].grades[p]);
		}
		printf("\n\t-----------------------------------\n");
	}
}
