#include<iostream>

//ָ�룺
// 1.�ַ�ָ��
// 2.����ָ��
// 3.ָ������
// 4.���鴫�κ�ָ�봫��
// 5.����ָ��
// 6.����ָ������
// 7.ָ����ָ������ָ��
// 8.�ص�����
// 9.ָ����������
//
//ָ����
// 1.ָ�����һ��������������ŵ�ַ����ַΨһ��ʶһ���ڴ�ռ�
// 2.ָ���С�ǹ̶��ģ�4/8�ֽڣ���32/64λƽ̨��
// 3��ָ���������ͣ�ָ������;�����ָ���+-�����Ĳ�����ָ�������ʱ��Ȩ��
// 4.ָ�������
//
//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", sz);
//}
//int main()
//{
//	int arr[10] = { 0 };
//	test(arr);//64λƽ̨һ��ָ���СΪ8�ֽ�
//	return 0;
//}
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	char* pc = arr;
//	printf("%s\n", arr);
//	printf("%s\n", pc);
//	return 0;
//}
//int main()
//{
//	char* p = (char*)"abcdef";//"abcdsf"��һ�������ַ���,�ò����ǰ��ַ��������ַ���ַ����ָ��p��ע�⣺�˴�ָ�����Ϊ������
//	
//	printf("%s\n", p);
//	printf("%c\n", *p);//ֻ��ӡ��һ���ַ�
//	return 0;
//}
//
//int main()
//{
//	/*char str1[] = "hello world";
//	char str2[] = "hello world";
//	const char* str3 = "hello world";
//	const char* str4 = "hello world";
//
//	if (str1 == str2)
//	{
//		printf("str1 and str2 are the same\n");
//	}
//	else
//	{
//		printf("str1 and str2 are different\n");
//	}
//	if (str3 == str4)
//	{
//		printf("str3 and str4 are the same\n");
//	}
//	else
//	{
//		printf("str3 and str4 are different\n");
//	}*/
//	const char str1[] = "abc";
//	const char str2[] = "abc";
//	//��ַ��ͬ
//	const char* p1 = "abc";
//	const char* p2 = "abc";
//	//��ַ��ͬ
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };//��������
//	char ch[5] = { 0 };//�ַ�����
//	int* parr[4];//�������ָ�������--ָ������
//	char* pch[5];//����ַ�ָ�������--ָ������
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int* arr[4] = { &a,&b,&c,&d };
//	int i = 0;
//	for ( i = 0; i < 4; i++)
//	{
//		printf("%d ", *(arr[i]));
//	}
//	return 0;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for ( j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	//char arr1[] = "abcdef";
//	//char arr2[] = "abcdef";
//	//const char* p1 = "abcdef";
//	//const char* p2 = "abcdef";
//	//if (p1==p2)
//	//{
//	//	printf("hehe\n");//����ָ��洢��ַһ���������ַ�����
//	//}
//	//else
//	//{
//	//	printf("haha\n");
//	//}
//
//	//char arr1[] = "abcdef";
//	//char arr2[] = "abcdef";
//	//const char* p1 = "abcdef";
//	//const char* p2 = "abcdef";
//	//if (arr1==arr2)
//	//{
//	//	printf("hehe\n");
//	//}
//	//else
//	//{
//	//	printf("haha\n");//�����ַ�����ĵ�ַ��ͬ����Ȼ�ڲ�Ԫ����ͬ
//	//}
//	return 0;
//}
//int main()
//{
//	/*char str1[] = "ooo";
//	char str2[] = "www";
//	strcat(str1, " ");
//	strcat(str1, str2);
//	printf("str1=%s\n", str1);*/
//	return 0;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for ( j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//����ָ�룺
//����ָ�붨�壺
// ����ָ����ָ�룬���ܹ�ָ�������ָ��
//
//int main()
//{
//	//int* p = NULL;//����ָ��--ָ�����͵�ָ��--���Դ�����εĵ�ַ
//	//char* pc = NULL;//�ַ�ָ��--ָ�������ָ��--���Դ������ĵ�ַ
// //       			//����ָ��--ָ�������ָ��--�������ĵ�ַ
//	//int arr[10] = { 0 };
//	////arr-��Ԫ�ص�ַ
//	////&arr[10]-��Ԫ�صĵ�ַ
//	////&arr������ĵ�ַ
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;//����ĵ�ַҪ������--p��һ������ָ�룬ָ��һ������
//
//	return 0;
//}

//int main()
//{
//	char* arr[5];
//	char* (*pa)[5] = &arr;//pa--ָ������� ��*˵��pa��ָ��
//	int arr2[10] = { 0 };
//	int (*pa2)[10] = &arr2;//&arr��ʾ���Ƕ���һ��ָ�룬��������ĵ�ַ��������������Ԫ�صĵ�ַ
//	return 0;
//}
//int main()
//{
//	/*int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
//	int(*pa)[10] = &arr;
//	int i = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d ",(*pa)[i]);
//		printf("%d ", *(*pa + i));
//
//	}*///����ָ�������ôʹ�ã�������Ҫ
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}//��Ϊ����ʵ��
//	return 0;
//}

//�������������ʽ
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for ( i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////������ָ�����ʽ
//void print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			/*printf("%d ", *(*(p + i) + j));*/
//			printf("%d ", p[i][j]);//*(p+i)==p[i];*(*(p+i)+j)==p[i][j]
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print1(arr, 3, 5);//arr-������--��Ԫ�ص�ַ
//	//��arr���һά����
//	printf("\n");
//	print2(arr, 3, 5);
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int i = 0;
//	//int* p = arr;
//	//for ( i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", p[i]);
//	//	printf("%d ", *(p + i));
//	//	printf("%d ", *(arr + i));
//	//	printf("%d ", arr[i]);//arr[i]==*(arr+i)==*(p+i)==p[i]
//	//}
//	return 0;
//}


//int main()
//{
//	//�ַ�ָ�룺
//	char ch = 'w';
//	char* p = &ch;
//	const char *p2 = "abcdef";//�����ַ���
//	//ָ������--����--���ָ������飺
//	int* arr[10];
//	char* ch[5];
//	//����ָ�룺
//	//int* p1;//����ָ��--ָ�����͵�ָ��
//	//char* p2;//�ַ�ָ��--ָ���ַ���
//
//	int arr2[5];//����
//	int(*pa)[5] = &arr2;//ȡ������ĵ�ַ��pa����һ������ָ��
//
//	int(*parr3[10])[5];//����ָ�������
//	return 0;
//}
