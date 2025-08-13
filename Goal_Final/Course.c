//所有对课程操作的子程序所在文件
#include"head.h"
struct Course_List* New_Course;
struct Course_List* Still_Course;




void EditCourse(struct LINK* head)
{
	New_Course = (struct Course_List*)malloc(sizeof(struct Course_List));
	int choice;
	do
	{
		choice = EditMenu();
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
void TestCourse()
{
	
}
int* Search_Course(struct Course_List *head)
{
	//p是当前节点，pr为下一节点
	if (head == NULL)
	{
		head = p;
		head->next = NULL;
		return head;
	}
	else
	{
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
		p->next = NULL;
	}
}
void AddCourse(struct Course_List *head)
{
	struct Course_List* new_Course = NULL;
	struct Course_List* Still_Course = head;
	new_Course = (struct Course_List*)malloc(sizeof(struct Course_List));
	//printf("There're totally %d courses recorded:");
b1:
	printf("Enter NEW course ID (Character+Number, lenghth < 10) or any single key back:");
	char ch1[10];
	scanf("%s", ch1);
	int sz = sizeof(ch1) / sizeof ch1[0];
	if (sz > 1)
	{
		*new_Course->course.courseID = ch1[10];
		while (Still_Course != NULL)
		{
			if (Still_Course->course.courseID == new_Course->course.courseID)
			{
				printf("ID is existed, please enter again\n");
				Still_Course = head->next;
				goto b1;
			}
			else
			{
			b2:
				printf("Enter course name (less than 50 characters with spaces):");
				char ch2[50];
				scanf("%s", ch2);
				sz = sizeof(ch2) / sizeof(ch2[0]);
				if (sz > 0)
				{
					*new_Course->course.coursename = ch2[50];
					printf("Add course successfully but evaluation items.\n\n");
					printf("The newly added course is %s, %s.", *new_Course->course.courseID, *new_Course->course.coursename);//还有问题
				}
				else
				{
					goto b2;
				}
			}
		}
	}
	else
	{
		goto b1;
	}
	new_Course->next = head->next;
	head->next = new_Course;
}
void DeleteCourse(struct LINK* head)
{

}
void DeleteAllCourses(struct LINK* head)
{

}
void ModifyCourse(struct LINK* head)
{

}