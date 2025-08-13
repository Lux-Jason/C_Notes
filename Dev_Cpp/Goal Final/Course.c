//所有对课程操作的子程序所在文件
#include"head.h"

void EditCourse()
{
	int choice;
	do
	{
		EditMenu();
		printf("Enter a number and choose an choiceation:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: 
			AddCourse();
			// Add Course
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
	} while (choice!=5);

}
void ViewCourse()
{

}
void AddCourse()
{

}
void DeleteCourse()
{

}
void DeleteAllCourses()
{

}
void ModifyCourse()
{

}
