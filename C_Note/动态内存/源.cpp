#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//int main()
//{
//	int n = 0;
//	char ch = 'a';
//	int arr[10] = { 0 };//�����ڴ�ռ��Ѿ��̶�������
//	//���ܿ��ٵĿռ�С���ߴ��ˣ����޷��ı�
//	return 0;
//}

//��̬�ڴ���䣬�漰�ĸ�������malloc��free,calloc,realloc

//int main()
//{
//	//void* p = malloc(40);//mallocֻ֪��������ռ䣬����֪�����ʲô���͵����ݣ�����mallocֻ�ܷ���void*��ָ��
//	//int* p = (int*)malloc(10*sizeof(int));//����ֵ������Ὺ��ʧ��
//	int* p = (int*)calloc(10, sizeof(int));
//	//40Bytes
//	//��malloc����ʧ�ܣ��򷵻ؿ�ָ�룬����Ҫ�Է���ֵ�����
//	if (p == NULL)
//	{
//		perror("malloc");//malloc: Not enough space
//		return 1;
//	}
//	int i = 0;
//	//ʹ��
//	/*for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}*/
//	/*for (i = 0; i < 10; i++)
//	{
//		*p = i;
//		p++;
//	}*/
//	for (i = 0; i < 10; i++)
//	{
//		printf("%x ", *(p + i));//malloc:0 1 2 3 4 5 6 7 8 9
//								//(δ��ʼ��)
//								//mallloc��cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd cdcdcdcd
//								//calloc��0 0 0 0 0 0 0 0 0 0��calloc������ռ�ֱ�ӳ�ʼ����
//	}
//	//malloc����Ŀռ��ڶ���
//	
//	//�ռ䲻������Ҫ����ռ�--realloc
//	//realloc(p, 20 * sizeof(int));
//	//realloc�����ռ�ʧ��--���ؿ�ָ��
//	//��������ɹ���Ҳ�����������
//	// ���1�����Ѿ����ٺõĿռ��ߣ�û���㹻�ռ�ֱ�ӽ��пռ����������������£�realloc�����ڴ����������һ��ռ䣨�����µĿռ�Ĵ�С����
//	// ͬʱ�ѾɵĿռ�����ݿ������µĿռ䣬Ȼ���ͷžɵĿռ䣬ͬʱ�����µĿռ����ʼ��ַ
//	// 
//	// ���2�����Ѿ����ٺõĿռ��ߣ����㹻�Ŀռ䣬ֱ�ӽ�������
//	// ֱ�ӷ��ؾɵĿռ����ʼ��ַ
//	int* ptr = (int*)realloc(p, 20 * sizeof(int));
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	else
//	{
//		perror("realloc");
//		return 1;
//	}
//	//realloc�����ܵ����ռ䣬����ʵ�ֺ�mallocһ���Ĺ���
//
//	//�ͷſռ䣺
//	//void free(void* ptr);--�������ptrָ��Ŀռ䲻�Ƕ�̬���ٵģ���free��������Ϊ��δ�����
//	//�������ptr��NULLָ�룬����ʲô�¶�����
//	//malloc��free����������<stdlib.h>ͷ�ļ���
//	free(p);
//	p = NULL;//��ֹp��ΪҰָ��
//	return 0;
//}

//realloc��malloc���Եȼ�
//int main()
//{
//	int* p = (int*)realloc(NULL, 40);//��һ������Ϊ��ָ�룬����Եȼ���malloc
//	free(p);
//	p = NULL;
//	return 0;
//}

//������̬���ٵĴ���
//1.�Կ�ָ����в���
//int main()
//{
//	int* p = (int*)malloc(100);
//	*p = 20;//p�п���Ϊ��ָ��
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	*p = 20;
//	free(p);
//	p = NULL;
//	return 0;
//}

//2.�Զ�̬���ٿռ��Խ�����
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;//��ѭ������ʮһ��ʱ����Խ�������
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//int main()
//{
//	int a = 0;
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	p = &a;//pָ��Ŀռ䲻���Ƕ����ϵĿռ�
//	free(p);//��ʱ�ͷŻ���ɳ������
//	p = NULL;
//	return 0;
//}

//malloc/calloc/realloc����Ŀռ�
//����������ͷţ������������ǲ������ٵ�
// 
//�ͷŵķ�ʽ��
//1.free�����ͷ�
//2.ֱ������������ɲ���ϵͳ����

//int* test()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return NULL;
//	}
//	else
//	{
//		return p;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}

//4.ʹ��free�ͷŶ�̬���ٿռ��һ����
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	p++;
//	free(p);
//	p = NULL;
//	return 0;
//}

//5.��ͬһ�鶯̬�ڴ�Ķ���ͷ�
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 1;
//	}
//	free(p);
//	p = NULL;//����ʹ��p����Ϊ��ָ�룬���ظ��ͷ�Ҳ�����������
//	free(p);
//	p = NULL;
//	return 0;
//}

//6.��̬�ڴ������ͷţ��ڴ�й©��
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return;
//	}
//	else
//	{
//		*p = 20;
//		return;//����ǰ���������޷��ͷ�
//	}
//
//	free(p);
//	p = NULL;
//
//}
//int main()
//{
//	test();
//	while (1);
//	return 0;
//}
// 
// �Ҵ�
//#include<string.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return;
//	}
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "Hello World");//��NULLָ������ò������������
//	printf(str);//û����
//}
//int main()
//{
//	Test();
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", arr);
//	printf("abcdef\n");
//	printf(arr);
//	return 0;
//}
//1.GetMemory��������ֵ���ݵķ�ʽ���޷���maloc���ٿռ��ַ�����ط���str�У����ý�����str��Ȼ��NULLָ��
//2.strcpy��ʹ����str�����Ƕ�NULLָ������ò������������
//3.�ڴ�й©

//�޸ģ�
//#include<string.h>
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return;
//	}
//}
//char* GetMemory2(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "Hello World");//��NULLָ������ò������������
//	printf(str);//û����
//	free(str);
//	str = NULL;
//
//	printf("\n");
//
//	char* str2 = NULL;
//	str2 = GetMemory2(str2);
//	strcpy(str2, "hello world");
//	printf(str2);//û����
//	free(str2);
//	str2 = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//char* GetMemory(void)
//{
//	char p[] = "hello world";//�ֲ����飬ֻ�ں����ڲ���������������
//	return p;//����������ʼ��ַ
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();//���غ��p����Ұָ��
//	printf(str);//������--δ��ʼ���Ĵ�ӡֵ
//}
//int main()
//{
//	Test();
//	return 0;
//}
//#include<string.h>
//void GetMemory(char** p,int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);//malloc����Ŀռ�û���ͷ�
//	//���ӣ�
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//#include<string.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	//�˴���str����Ұָ�룬��û����Ϊ��ָ��
//	if (str!=NULL)
//	{
//		strcpy(str, "world");//�Ƿ�����
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

//�������飺
//��C99�У��ṹ������һ��Ԫ��������δ֪��С�����飬��ͽ������������顱��Ա��
//struct st_type
//{
//	int i;
//	char c;
//	//int a[0];//��Щ���������ܱ���
//	int b[];//�ص㣺
//	//1.ǰ�����������һ��������Ա
//	//2.sizeof���ص����ֽṹ��С����������������ڴ�
//	//3.�������������Ա�Ľṹ��malloc���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С������Ӧ���������Ԥ�ڴ�С
//};
//struct St
//{
//	char c;
//	int n;
//	int arr[0];
//};
//int main()
//{
//	printf("%d\n", sizeof(char));//1
//	printf("%d\n", sizeof(int));//4
//	printf("%d\n", sizeof(St));//8�ֽ�
//	struct St* ps =(struct St*) malloc(sizeof(struct St) + 10 * sizeof(int));
//	if (ps == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	ps->c = 'w';
//	ps->n = 100;
//	for (int i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//����ռ䲻��
//	struct St* ptr = (struct St*)realloc(ps, sizeof(struct St) + 15 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps = ptr;
//		for (int i = 0; i < 10; i++)
//		{
//			printf("%d ", ps->arr[i]);//0 1 2 3 4 5 6 7 8 9
//		}
//		printf("\n");
//		printf("%c\n", ps->c);//w
//		printf("%d\n", ps->n);//100
//	}
//	else
//	{
//		perror("realloc");
//		return 1;
//	}
//	
//	free(ps);
//	ps = NULL;
//	return 0;
//}

struct St
{
	char c;
	int n;
	int* arr;
};
int main()
{
	struct St* ps = (struct St*)malloc(sizeof(struct St));
	if (ps == NULL)
	{
		perror("malloc");
		return 1;
	}

	ps->c = 'w';
	ps->n = 100;
	ps->arr = (int*)malloc(10 * sizeof(int));
	if (ps->arr == NULL)
	{
		perror("malloc-2");
		return 1;
	}
	//ʹ�ã�
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	//����ռ䲻����
	int* ptr = (int*)realloc(ps->arr, 15 * sizeof(int));
	if (ptr == NULL)
	{
		perror("realloc");
		return 1;
	}
	else
	{
		ps->arr = ptr;
	}
	//ʹ�ã�
	for ( i = 0; i < 15; i++)
	{
		ps->arr[i] = i;
	}

	for (i = 0; i < 15; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
	printf("%c\n", ps->c);
	printf("%d\n", ps->n);
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}
