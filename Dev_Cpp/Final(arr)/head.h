
#pragma once
#include <stdio.h>
#include<malloc.h>
#include<string.h>
//�궨�������С�����ڸ���
#define MAX_COURSE_ID 10//�γ�id����Ϊ10����ĿҪ��
#define MAX_COURSE_NAME 50//�γ����ִ�СΪ50����ĿҪ��
#define MAX_COURSE 10//�γ�����Ϊ10
#define MAX_ITEM_NAME 20//����������Ϊ20
#define MAX_ITEM_GRADES 20//һ�������������20�γɼ�
#define MAX_ITEM 5//�����5��

//�鳤���ȳ�������ɲ��֣�
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

//��Ա��������ɲ��֣��±���úʹ����߼����������⣬��ӡ��ʽ�����⣩��
void ViewCourse();
//��Ա�պ�����ɲ��֣������±��������bug�϶ࣩ��
void savefile();
void AllCourses();
void SingleCourse();
//��Ա�����᳢������expectedfinalgrade�Ĳ��ֺ������������ʽ�������������޷�ʹ�á�


typedef struct Item
{
	//��Courseǰ�����������޷�Ƕ��
	//each methods
	//ÿ����Ŀ��lab��assignment�ȣ���Ƕ���ڿγ���

	char   name[MAX_ITEM_NAME];
	float  percentage;
	float  grades[MAX_ITEM_GRADES];
	float  maxScore;
	int    numOfGrades;
}ITEM, * k;
typedef struct Course
{
	//the struct of Courses
	//�γ̽ṹ��

	char courseID[MAX_COURSE_ID];
	char coursename[MAX_COURSE_NAME];
	ITEM item[MAX_ITEM];
	float Final;//Lowest Final for Expected Course
	int data;
}Course, * C;
//����������struct CourseΪCourse
Course Course_arr[MAX_COURSE];//����ṹ������
int num_Courses;

