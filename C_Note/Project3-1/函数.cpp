#include<stdio.h>
#include<string.h>
#include<Windows.h>
//����(�⺯�����Զ��庯����
//
//
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}//�Զ��庯��
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//	//�⺯��
//	return 0;
//}
//#include<string.h>
//int main()
//{
//	char arr1[] = "bit";
//	char arr2[] = "###########";
//	strcpy(arr2, arr1);//string.h
//	printf("%s\n", arr2);
//	return 0;
//}
// 
// �����ӣ�
//#include <cstdio>
//#include <windows.h>
//#include <conio.h>
//
//char a[20][20] = { "##########",
//				"##     ###",
//				"##O###   #",
//				"# S  O O #",
//				"# **# O ##",
//				"##**#   ##",
//				"##########" };
//
//void Hide()
//{
//	HANDLE              hOut;
//	CONSOLE_CURSOR_INFO curInfo;
//
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	curInfo.dwSize = 1;
//	curInfo.bVisible = FALSE;
//	SetConsoleCursorInfo(hOut, &curInfo);
//}
//
//void Welcome()
//{
//	printf("\n\n            ������");
//	printf("\n\n     �밴�������ʼ");
//	_getch();
//	system("cls");
//}
//
//void Set()
//{
//	HANDLE hOut;
//	COORD pos = { 0,0 };
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(hOut, pos);
//}
//
//int main()
//{
//	Hide();
//	Welcome();
//	int x = 3, y = 2;
//	int cnt = 0;
//	for (int i = 0; i <= 6; i++)
//		puts(a[i]);
//	while (1)
//	{
//		char ch;
//		ch = _getch();
//		if (ch == 's')
//		{
//			if (a[x + 1][y] == ' ')
//			{
//				a[x][y] = ' ';
//				x++;
//				a[x][y] = 's';
//			}
//			else if (a[x + 1][y] == 'O')
//			{
//				if (a[x + 2][y] == ' ')
//				{
//					a[x][y] = ' ';
//					x++;
//					a[x][y] = 's';
//					a[x + 1][y] = 'O';
//					cnt++;
//				}
//				else if (a[x + 2][y] == '*')
//				{
//					a[x][y] = ' ';
//					x++;
//					a[x][y] = 's';
//					a[x + 1][y] = ' ';
//					cnt++;
//				}
//			}
//		}
//		else if (ch == 'w')
//		{
//			if (a[x - 1][y] == ' ')
//			{
//				a[x][y] = ' ';
//				x--;
//				a[x][y] = 's';
//			}
//			else if (a[x - 1][y] == 'O')
//			{
//				if (a[x - 2][y] == ' ')
//				{
//					a[x][y] = ' ';
//					x--;
//					a[x][y] = 's';
//					a[x - 1][y] = 'O';
//					cnt++;
//				}
//				else if (a[x - 2][y] == '*')
//				{
//					a[x][y] = ' ';
//					x--;
//					a[x][y] = 's';
//					a[x - 1][y] = ' ';
//					cnt++;
//				}
//			}
//		}
//		else if (ch == 'a')
//		{
//			if (a[x][y - 1] == ' ')
//			{
//				a[x][y] = ' ';
//				y--;
//				a[x][y] = 's';
//			}
//			else if (a[x][y - 1] == 'O')
//			{
//				if (a[x][y - 2] == ' ')
//				{
//					a[x][y] = ' ';
//					y--;
//					a[x][y] = 's';
//					a[x][y - 1] = 'O';
//					cnt++;
//				}
//				else if (a[x][y - 2] == '*')
//				{
//					a[x][y] = ' ';
//					y--;
//					a[x][y] = 's';
//					a[x][y - 1] = ' ';
//					cnt++;
//				}
//			}
//		}
//		else if (ch == 'd')
//		{
//			if (a[x][y + 1] == ' ')
//			{
//				a[x][y] = ' ';
//				y++;
//				a[x][y] = 's';
//			}
//			else if (a[x][y + 1] == 'O')
//			{
//				if (a[x][y + 2] == ' ')
//				{
//					a[x][y] = ' ';
//					y++;
//					a[x][y] = 's';
//					a[x][y + 1] = 'O';
//					cnt++;
//				}
//				else if (a[x][y + 2] == '*')
//				{
//					a[x][y] = ' ';
//					y++;
//					a[x][y] = 's';
//					a[x][y + 1] = ' ';
//					cnt++;
//				}
//			}
//		}
//		Set();
//		for (int i = 0; i <= 6; i++)
//			puts(a[i]);
//		if (cnt == 4)
//			break;
//	}
//	printf("��Ӯ�ˣ�");
//	Sleep(10000);
//	return 0;
//}
//memory--�ڴ�(�ַ�������ASC�洢��
//memset--�ڴ�����
//
//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, '*', 5);
//	printf("%s\n", arr);//***** world
//	return 0;
//}
//
//�Զ��庯�����Լ���ƺ��������������ͣ���������
//ret_type(�������ͣ� fun_name����������(paral������������, *)
//{
//	statment;������
//}
//��ȣ�
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}//�Զ��庯��
//дһ���������ҳ������������ֵ��
//int get_max(int x, int y, int z)
//{
//	int max = x;
//	if (y > max)
//	{
//		max = y;
//	}
//	else if (z > max)
//	{
//		max = z;
//	}
//	
//	return max;
//}
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	int max = get_max(a, b, c);
//	printf("max=%d\n", max);
//	return 0;
//}
//
//дһ��������������������֮������ݣ�
//int main()
//{
//	int a = 0;
//	int b = 20;
//	int tmp = 0;
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}//������д��
//void Swap1(int x, int y)
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//	return x, y;
//}//������
//void Swap2(int* px, int* py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}//�Զ��庯��д��
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("a=%d b=%d\n", a, b);
//	/*int* pa = &a;
//	int* pb = &b;*/
//	Swap2(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}
//ʵ��--ʵ�ʲ�������ʵ���������Ĳ������������Ǳ�������������Ŷ��ʦ�������ȣ��������࣬�ڵ���ʱ��������ȷ����ֵ���Ա㽫��Щֵ�����βΡ�
//�β�--��ʽ��������ʽ�ϵĲ�������ֻ�ں����ڲ���Ч���ں������õĹ����в�ʵ����������������ɺ����١�
//
//
//дһ���������ж�һ�����ǲ���������
//#include<math.h>
//int prime(int n)
//{
//	//2~n-1
//	int j = 0;
//	for (int j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//			return 0;
//	}
//	//if (j==n)
//	return 1;
//}//����������1��������������0
//int main()
//{
//	int i = 0;
//	for ( i = 2; i <= 200; i++)
//	{
//		if (prime(i) == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}
//
//дһ���������ж�һ�����������
//int is_leap_year(int y)
//{
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		//�ж�year�Ƿ�Ϊ����
//		if (1 == is_leap_year(year))
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}
//
//
//����ʵ�ֶ��ֲ��ң�
//int binary_search(int arr[], int k,int sz)//������arr[]��һ��ָ��
//{
//	//�㷨��ʵ��
//	int left = 0;
//	int right = sz - 1;
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;//�м�Ԫ�ص��±�
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	//���ֲ���
//	//��һ�����������в��Ҿ����ĳ����
//	//�ҵ��˷����±꣬�Ҳ�������-1
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &k);
//	int ret = binary_search(arr, k, sz);//���ݹ�ȥ����arr��Ԫ�صĵ�ַ
//	if (ret == -1)
//	{
//		printf("�Ҳ���ָ��������\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
//	}
//	return 0;
//}
//
//
//дһ��������ÿ����һ�Σ�numֵ��1��
//void Add(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("num=%d\n", num);//1
//	Add(&num);
//	printf("num=%d\n", num);//2
//	Add(&num);
//	printf("num=%d\n", num);//3
//	return 0;
//}
//������Ƕ�׵��úͷ��ʣ�
//void new_line()
//{
//	printf("haha\n");
//}
//void three_line()
//{
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		new_line();
//	}
//}
//int main()
//{
//	three_line();
//	return 0;
//}
//
//
// ��ʽ���ʣ���һ�������ķ���ֵ��Ϊ��һ�������Ĳ�������
//int main()
//{
//	int len = 0;
//	//��һ�֣�
//	len = strlen("abc");
//	printf("%d\n", len);
//	//�ڶ��֣�
//	printf("%d\n", strlen("abc"));
//	return 0;
//}
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));//printf��ӡ��Ϊ�����ķ���ֵ--printf����������Ϊ����
//	return 0;
//}
//#include "ADD.h"//��Դ�ļ��ж��庯������ͷ�ļ���������������ֱ������ͷ�ļ��Ե��ú�������ģ��д����
////��������ʹ��
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int sum = 0;
//	sum = Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//}
