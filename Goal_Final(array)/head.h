//头文件，所有子程序声明的地方，如果需要引用其他头文件，也只需在此处引用
//源文件内最好只引用该头文件
//ATTENTION：函数和结构体声明有先后顺序，一定要注意！
#pragma once
#include <stdio.h>
#include<malloc.h>
#include<string.h>
//宏定义数组大小，便于更改
#define MAX_COURSE_ID 10//课程id长度为10（项目要求）
#define MAX_COURSE_NAME 50//课程名字大小为50（项目要求）
#define MAX_COURSE 10//课程数量为10
#define MAX_ITEM_NAME 20//考核项名字为20
#define MAX_ITEM_GRADES 20//一个考核项可以有20次成绩
#define MAX_ITEM 5//考核项共5个

void savefile();
void EditCourse();
void ViewCourse();
void AddCourse();
void DeleteCourse();
void DeleteAllCourses();

void ModifyCourse();
void M_Course_name(int n);
void M_Item_name(int n);
void M_Item_percentage(int n);
void M_Item_Fullmark(int n);

void Add_Item_ifnone(int n);
void EditGrade();
void AddGrade(int n,int m,int count);
void DeleteGrade(int n,int m,int count);
void DeleteAllGrades(int n,int m,int count);
void ModifyGrade(int n,int m,int count);
void ExpectedFinalGrade();
void AllCourses();
void SingleCourse();

int MainMenu();
int EditCourse_Menu();
int EditGrade_Menu();
int Final_Menu();

int charToInt(char c);

typedef struct Item
{
	//在Course前声明，否则无法嵌套
	//each methods
	//每个项目（lab，assignment等），嵌套在课程中

	char   name[MAX_ITEM_NAME];
	float  percentage;
	float  grades[MAX_ITEM_GRADES];
	float  maxScore;
	int    numOfGrades;
}ITEM, * k;
typedef struct Course
{
	//the struct of Courses
	//课程结构体

	char courseID[MAX_COURSE_ID];
	char coursename[MAX_COURSE_NAME];
	ITEM item[MAX_ITEM];
	float Final;//Lowest Final for Expected Course
	int data;
}Course, * C;
//重命名定义struct Course为Course
Course Course_arr[MAX_COURSE];//定义结构体数组
int num_Courses;

