#include<stdio.h>
#include<iostream>
//�ṹ�壺
// 1.��������
//2.��ʼ��
//3.��Ա����
//4.����
//�ṹ��
//�ṹ��һЩֵ�ļ��ϣ���Щֵ����Ϊ��Ա�������ṹ��ÿ����Ա�����ǲ�ͬ���͵ı�����

//�ṹ��������
//struct tag
//{
//	member - list;
//
//
//}variable -  ist;(�����б�

//struct--�ṹ��ؼ��֣�Stu--�ṹ���ǩ��struct Stu--�ṹ������
//����һ���ṹ�����ͣ�����ռ���ڴ�ռ䣩
//struct Stu
//{
//	//����һ��ѧ����
//	char name;
//	char sex[5];
//	int age;
//	char tel[12];
//}S1, S2, S3;//����ȫ�ֵĽṹ��������������ã�
//typedef struct Stu//��������
//{
//	char name;
//	char sex[5];
//	int age;
//	char tel[12];
//}Stu;//struct Stu-->Stu
//int main()
//{
//	struct Stu S1;//Sռ���ڴ�ռ䣨�ֲ�������
//	Stu S2;
//	return 0;
//}
//�ṹ���Ա�������κ����͵ı���
//�ṹ������Ķ��弰��ʼ����
//struct Point
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//typedef struct Stu//��������
//{
//	char name[10];
//	char sex[7];
//	int age;
//	char tel[12];
//	struct Point P;
//	char* pc;
//}Stu;
//void Print2(struct Point* ps)
//{
//	printf("%d ", ps->a);
//	printf("%s ", ps->c);
//	printf("%s ", ps->arr[20]);
//	printf("%lf", ps->d);
//	printf("\n");
//}
//void Print1(Stu tmp1)
//{
//	printf("name=%s\n", tmp1.name);
//	printf("sex=%s\n", tmp1.sex);
//	printf("age=%d\n", tmp1.age);
//	printf("tel=%s\n", tmp1.tel);
//	printf("%s\n", tmp1.pc);
//}
//int main() 
//{
//	char arr[] = "hello bit\n";
//	Stu S1 = { "John","male",20,"5764975" };//�ֲ�����
//	struct Stu S2 = { "Kiky","secret",30,"20391837",{100,'w',"hello world",3.14},arr };
//	/*printf("%s\n", S2.P.arr);*/
//	Print1(S2);
//	return 0;
//}
//�C�����ֲ������������βΣ��������ÿ��ٿռ�
//��������̬�ڴ���䣻malloc/free��realloc��ralloc
//ȫ������
// ȫ�ֱ�������ȫ�ֱ�����
// ��̬����������̬������static���Σ���������̬�ֲ������;�̬ȫ�ֱ���
// ���������ַ�������const���ε�ȫ�ֱ��������������ݲ��ɸ��ģ�
//
//���ݽṹ��
//1.�������ݽṹ��
// ˳���
// ����
// ջ���Ƚ�ȥ�ĺ�������ȥ���ȳ�
//   ѹջ������һ��Ԫ��
//   ��ջ��ɾ��һ��Ԫ��
//		�ṹ�崫��ʱ��Ҫ���ṹ���ַ
// ����
// 2.�������ݽṹ��
// ������
// 3.ͼ��
//