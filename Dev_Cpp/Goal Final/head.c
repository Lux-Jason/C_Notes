//头文件，所有子程序声明的地方，如果需要引用其他头文件，也只需在此处引用
//源文件内最好只引用该头文件
//ATTENTION：函数和结构体声明有先后顺序，一定要注意！
#pragma once
#include <stdio.h>
void EditCourse();
void MainMenu();
void EditMenu();
void ViewCourse();
void AddCourse();
void DeleteCourse();
void DeleteAllCourses();
void ModifyCourse();

void EditGrade();
void ExpectedFinalGrade();
typedef struct Item
{
	//在Course前声明，否则无法嵌套
	//each methods
	//每个项目（lab，assignment等），嵌套在课程中

	char   name[20];
	float  percentage;
	float  grades[20];
	float  maxScore;
	int    numOfGrades;
}ITEM, * k;
typedef struct Course
{
	//the struct of Courses
	//课程结构体

	int coursecode;
	char coursename[20];
	ITEM assignment;
	ITEM Lab;
	ITEM exericise;
	ITEM project;
	ITEM examination;
	float Final;//Lowest Final for Expected Course
};
