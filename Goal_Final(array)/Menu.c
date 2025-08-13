//菜单文件：存放各种打印的菜单
//选择操作可以在菜单内完成，减少子程序的工作量
#include"head.h"

int MainMenu()
{
	int choice;
	do
	{
		printf("\n============== Main Menu ==============\n");
		printf("\t1. Edit Course\n");
		printf("\t2. Edit Grade\n");
		printf("\t3. Expected Final Grade\n");
		printf("\t4. View Course\n");
		printf("\t5. Exit\n");
		printf("=======================================\n\n");
		printf("Enter a number and choose an choiceation:");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 5);
	return choice;
}
int EditCourse_Menu()
{
	int choice;
	do
	{
		printf("\n============== Edit Course ==============\n");
		printf("\t1. Add Course\n");
		printf("\t2. Delete Course\n");
		printf("\t3. Delete All Courses\n");
		printf("\t4. Modify Course\n");
		printf("\t5. Back\n");
		printf("=========================================\n\n");
		printf("Enter a number and choose an choiceation:");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 5);
	return choice;
}

int EditGrade_Menu()
{
	int choice;
	do
	{
		printf("\n============== Edit Grade ==============\n");
		printf("\t1. Add Grade\n");
		printf("\t2. Delete Grade\n");
		printf("\t3. Delete All Grades\n");
		printf("\t4. Modify Grade\n");
		printf("\t5. Back\n");
		printf("============================================\n\n");
		printf("Enter a number and choose an choiceation:");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 5);
	return choice;
}
int Final_Menu()
{
	int choice;
	do
	{
		printf("\n============== Calculate Expected Final ==============\n");
		printf("\t1. View All Courses\n");
		printf("\t2. View Single Course\n");
		printf("\t3. Back\n");
		printf("=======================================================\n\n");
		printf("Enter a number and choose an choiceation:");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 3);
	return choice;
}