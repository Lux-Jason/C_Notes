
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

//组长乔奕畅个人完成部分：
void EditCourse();
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

int charToInt(char c);

int MainMenu();
int EditCourse_Menu();
int EditGrade_Menu();
int Final_Menu();

//组员张雅雯完成部分（下标调用和代码逻辑部分有问题，打印格式有问题）：
void ViewCourse();
//组员苏海州完成部分（整体下标调用有误，bug较多）：
void savefile();
void AllCourses();
void SingleCourse();
//组员张雅玲尝试做了expectedfinalgrade的部分函数，但代码格式与整体相差过大无法使用。


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

