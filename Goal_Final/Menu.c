//�˵��ļ�����Ÿ��ִ�ӡ�Ĳ˵�
//ѡ����������ڲ˵�����ɣ������ӳ���Ĺ�����
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
	} while (choice < 1 || choice > 6);
	return choice;
}
int EditMenu()
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
	} while (choice < 1 || choice>6);
	return choice;
}