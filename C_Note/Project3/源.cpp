 #define _CRT_SECERT_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//��֧��ѭ�����
//��֧��䣺
//  if������else��������䣺
//int main()
//{
//	int a = 67;
//	if (a < 20)
//		printf("a");
//	else if (a >= 20 && a < 50)
//		printf("b");
//	else if (a >= 50 && a < 70)
//		printf("c");
//	else
//		printf("d");
//	return 0;
//}
//int main()
//{
//	/*int a = 5;
//	if (5 == a)
//		printf("hehe");*/
//
//		/*int a = 9;
//		int b = 8;
//		if (6 <= a)
//			if (8 == b)
//				printf("hehe");
//			else
//				printf("haha");
//		else
//			printf("heihei");*/
//
//	/*int a = 9;
//	int b = 8;
//	if (10 <= a)
//	{
//		if (0 == b)
//			printf("hehe");
//	}//��������ʹelse���һ��ifƥ��
//	else
//		printf("heihei");*/
//
//	return 0;
//}
//�ж�һ�����Ƿ�Ϊ����
//int main()
//{
//	int a = 5;
//	if (1 == a % 2)
//		printf("a������\n");
//	return 0;
//}
//��ӡ1~100�������
//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		if (1 == i % 2)
//		{
//			printf("i=%d\n",i);
//		}
//		i++;
//	}
//
//	
//	return 0;
//}

//  switch��䣺
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);//
//	switch (day)
//	{
//	default:
//		Printf("�������\n");
//		break;//����Ƿ������Ĵ���
//	case 1://ʶ������ĸ�ֵ
//		printf("����һ");
//		break;//����switch���
//	case 2:
//		printf("���ڶ�");
//		break;
//	case 3:
//		printf("������");
//		break;
//	case 4:
//		printf("������");
//		break;
//	case 5:
//		printf("������");
//		break;
//	case 6:
//		printf("������");
//		break;
//	case 7:
//		printf("������");
//		break;
//	}
//	
//	return 0;
//}
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)//��nΪ���
//	{
//	case 1:
//		m++;
//	case 2:
//	    n++;
//	case 3:
//		switch (n)//��ʱn=2����case2����
//	//switch����Ƕ��ʹ��
//		{
//		case 1:
//			n++;
//		case 2:
//			m++;
//			n++;
//			break;
//		}
//	case 4:
//		m++;
//		break;
//	default:
//		break;
//
//	}
//	printf("m=%d,n=%d\n", m, n);
//	return 0;
//}
//
//
//
//ѭ����䣺
//  while��䣺
//int main()
//{
//	/*while (1)
//		printf("haha\n");*///��ѭ��
//
//	int i = 1;
//	while (i<=10)
//	{
//		if (5 == i)
//			//break;//���ý���ѭ��
//			continue;//��������ѭ������Ĵ���--������벻ִ��
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}
// 
//int main()
//{
//	int ch = getchar();
//	putchar(ch);//putchar��ch��==printf��"%c\n",ch)
//
//	return 0;
//}//getchar--�����ַ���putchar--�������ӡ���ַ�
//int main()
//{
//	int ch = 0;
//	//ctrl+z
//	//EOF==End Of File-> -1
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//
//}
//int main()
//{
//	int ret = 0;
//	char password1[20] = { 0 };
//	char password2[20] = { 0 };
//	int ch = 0;
//	printf("����������:>");
//	scanf("%s", password1);//�������룬�������password������
//	//������ʣ��һ����\n'
//	//��ȡһ��'\n'
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	printf("��ȷ������:>");
//	scanf("%s", password2);
//    while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	if (strcmp( password2,password1)==0)//�ж��ַ������Ƿ�һ��
//	{
//		printf("��ȷ��(Y/N):>");
//		ret = getchar();
//		if ('Y' == ret)
//		{
//			printf("ȷ�ϳɹ�\n");
//		}
//		else
//		{
//			printf("ȷ�Ϸ���\n");
//		}
//	}
//	else
//		printf("���벻һ��\n");
//	return 0;
//}
//
//
//forѭ����
//int main()
//{
//	int i = 0;
//	//for ( i = 1; i <=10; i++)//��ʼ�����жϣ�����
//	//{
//	//	printf("%d\n", i);
//	//}
//	// 
//	for (i = 1; i <= 10; i++)
//	{
//		if (5 == i)
//			continue;//1,2,3,4,6,7,8,9,10
//		   // break;//1,2,3,4
//		printf("%d\n", i);
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		if (i = 5)//������forѭ�����ڲ��޸ı�������ֹforѭ��ʧȥ����
//			printf("hehe\n");
//		printf("haha\n");//������ѭ��
//	}
//	return 0;
// }
//int main()
//{
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int i = 0;
//	//for ( i = 0; i < 10; i++)//����ҿ�д��
//	//{
//	//	printf("%d\n", arr[i]);
//	//}
//
//	//for (;;) 
//	//	printf("haha");
//	//}//forѭ���ĳ�ʼ�����жϺ͵������ֶ�����ʡ��
//	////����ʡ���жϲ��֣�����Ϊ��Ϊ��
//	////������ʱĪʡ�Դ���
//
//	//int i = 0;
//	//int j = 0;
//	//for ( i = 0; i < 10; i++)
//	//{
//	//	//for (; j < 10; j++)
//	//	//{
//	//	//	printf("haha\n");
//	//	//}//��ӡʮ��
//	//	//for (j=0; j < 10; j++)
//	//	//	{
//	//	//		printf("haha\n");
//	//	//	}//��ӡһ�ٴ�
//	//}
//	int x, y;
//	for (x=0, y= 0; x<2&&y<5; ++x,y++)
//	{
//		printf("haha\n");
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++)//k=0Ϊ��
//		k++;//��ѭ��
//	return 0;
//}
//
//
//do...while��䣺(����ִ��һ�Σ�
//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d ", i);
//		i++;
//	} while (i<=10);
//	return 0;//��ӡ1~10
//}
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			continue;//��ѭ��
//		printf("%d\n", i);
//		i++;
//	} while (i <= 10);//�����жϲ���
//	
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			break;//��������
//		printf("%d\n", i);
//		i++;
//	} while (i <= 10);
//	//�������򣬽�������
//	return 0;
//}

//calculate:n!--һ��for��whileѭ��
//forѭ����
//int main()
//{
//	int ret = 1;
//	int n = 0;
//	int i = 1;
//	scanf("%d", &n);//�޶�i�����ֵΪn
//	for ( i= 1; i<= n; i++)
//	{
//		ret *= i;//i�Ľ׳�=ret=ret*i
//	}
//	printf("%d\n", ret);//����==����i�Ľ׳�
//	return 0;
//}
//whileѭ����
//int main()
//{
//	int ret = 1;
//	int n = 0;
//	int i = 1;
//	scanf("%d" ,&n);
//	while (i <= n)
//	{
//		ret *= i;
//		i++;
//	}
//	printf("%d\n", ret);
//	return 0;
//}
//do...while��䣺
//int main()
//{
//	int ret = 1;
//	int n = 0;
//	int i = 1;
//	scanf("%d", &n);
//	do
//	{
//		ret *= i;
//		i++;
//	} while (i <= n);
//	printf("%d\n", ret);
//	return 0;
//}
//�ݹ麯������
//int Fact(int n);
//int Fact(int n)//�ݹ麯�� 
//{
//    int res = n;
//    if (n > 1)
//        res = res * Fact(n - 1);
//    return res;
//}
//int main()
//{
//    int n, cnt;
//    scanf("%d", &n);
//    cnt = Fact(n);
//    printf("%d\n", cnt);
//    return 0;
//}

//дһ�����룬��arr�������ҵ������һ������
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &k);
//	for ( i = 0; i < sz; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("�ҵ���,�±��ǣ�%d\n",i);
//			break;
//		}
//	}
//	if (i == sz)
//		printf("�Ҳ���\n");
//	return 0;
//}
// 
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	int left = 0;//���±�
//	int right = sz-1;//���±�
//	scanf("%d", &k);
//	while (left<=right)//ֻ�������������˵�������м�Ԫ��
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±��ǣ�%d\n", mid);
//			break;
//		}//���ֲ���ѭ����
//	}
//	if(left>right)//����Ԫ���м����м�Ԫ��
//	{ 
//		printf("�Ҳ���");
//	}
//	return 0;//**ֻ��Ԫ�أ�����������һ����Ԫ�أ�Ҳֻ��ӡ����һ��
//}


// �׳����㣺
//#define EOF (-1)
//int main()
//{
//	long long a;
//	int i;
//    int x;
//	int n;
//	while (scanf("%d %d", &x, &n) != EOF)
//	{
//		a = 1;
//		for (i = 0; i < n; i++)
//		{
//			a = a * x;
//		}
//		printf("%lld\n", a);
//	}
//	return 0;
//}


//��д���룬��ʾ����ַ��������ƶ������м��ۣ�
//#include<Windows.h>
//#include<stdlib.h>
//int main()
//{
//	//welcome to uic
//	char arr1[] = "welcome to uic";
//	char arr2[] = "##############";
//	int left = 0;
//	//int right = sizeof(arr1) / sizeof(arr1[0]) - 2;//����/0���鷳�������
//	int right = strlen(arr1) - 1;//�������
//	//��arr1�е�Ԫ�ظ�ֵ��arr2
//	while (left<=right)
//	{
//	arr2[left] = arr1[left];
//	arr2[right] = arr1[right];
//	printf("%s\n", arr2);
//	Sleep(1000);
//	system("cls");//ִ��ϵͳ�����һ������--cls�������Ļ��
//	left++;
//	right--;
//	}
//	return 0;
//}


//ģ���û���¼�龰����ֻ�ܵ�½���Σ������������룬���������޷���¼��
//int main()
//{
//	char password[20];
//	int i = 0;
//	for ( i = 0; i <3; i++)
//	{
//		printf("����������:>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		
//		else
//		{
//			printf("�������\n");
//		}
//	}
//
//	if (i >= 3)
//		printf("��֤ʧ��\n");
//	return 0;
//}
//.................................................................
//��ϰ��
// 
//��д����ʵ���������Ӵ�С���У�
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d > %d > %d\n", a, b, c);
//		return 0;
//}
//
//���������--շת�����:
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//	scanf("%d %d", &m, &n);
//	while (r = m % n)
//	{
//		//r = m % n;
//		m = n;
//		n = r;
//	}
//	printf("%d\n", n);
//	return 0;
//}
//
//��ӡ����:
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for ( year = 1000; year <=2000; year++)//��1000��2000�������
//	{
//		////�ܱ�4�����ķ�������
//		////�ܱ�400������������
//		//if (year % 4 == 0 && year % 100 != 0)
//		//{
//		//	printf("%d ", year);
//		//	count++;
//		//}
//		//else if (year % 400 == 0)
//		//{
//		//	printf("%d ", year);
//		//	count++;
//		//}
//		if (((year%4==0)&&(year%100!=0))||(year%400==0))
//		{
//			printf("%d ", year);
//			count++;
//		}
//
//	}
//	printf("\n�ܼ�:%d\n", count);
//	return 0;
//}
//
//��ӡ����(����):
//#include <math.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 2; i <= 200; i++)
//	{
//		//�����жϹ���
//		//ֻ�ܱ�1��������
//		////1.�Գ���--����2~i-1������(Ч���ϲ�):
//		//int j = 0;
//		//for (j = 2; j < i; j++)
//		//{
//		//	if (i % j == 0)
//		//	{
//		//		break;
//		//	}
//		//}
//		//if (j == i)
//		//{
//		//	count++;
//		//	printf("%d ", i);
//		//}
//		//2.��ƽ����(sqrt�⺯��)(�Ż�):
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j >sqrt (i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\n������:%d��\n", count);
//	return 0;
//}
//
//����0~100�ں�����"9"�ĸ���:
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for ( i = 0; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)
//			count++;
//	}
//	//9,19,29......99-10
//	//90,91,92,......99-10
//	printf("%d\n", count);
//	return 0;
//}
//
//�������:
//��1-1/2+1/3-1/4+...+1/99-1/100��ֵ,��ӡ���
//int main()
//{
//	int i = 0; 
//	double sum = 0.0;
//	int flag = 1;
//	for ( i = 1; i <=100; i++)
//	{
//		sum += flag*1.0 / i;
//		flag = -flag;
//	}
//	printf("sum=%lf\n", sum);
//	return 0;
//}
//
//�����ֵ:
//���Ǹ����������ֵ
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = arr[0];
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz ;i++)
//	{
//		if (arr[i] > max)
//		{
//		 max = arr[i];
//		}
//	}
//	printf("max=%d\n", max);
//	return 0;
//}
//
//��ӡ99�˷���:
//int main()
//{
//	int i = 0;
//	for ( i = 1; i <= 9; i++)
//	{
//		int j = 1;
//		for ( j = 1; j <=i; j++)
//		{
//			printf("%d*%d=%-2d ", j, i, i * j);//%2d��ʾ��ӡ��λ,������λ�ÿո���--%-2d���ʾ���ҵ�����λ
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//���ֲ���:
//��һ���������������в���һ���������
//int main()
//{
//	int arr[] = { 1,2,3,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	int left = 0;
//	int right = sz-1;
//	scanf("%d", &k);
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ���,�±���:%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//     printf("�Ҳ���");
//	}
//	return 0;
//}//д��һ��,��394��
//
//��������Ϸ��
//1.�����������һ������
//2.������
//#include<stdlib.h>
//#include<time.h>//ʹ��time����
//void menu()
//{
//	printf("**********************************\n");
//	printf("********1,play      0,exit********\n");
//	printf("**********************************\n");
//}
//void game()
//{
//	//1.����һ�������
//	int ret = 0;
//	int guess = 0;//���ղµ�����
//	//��ʱ����������������������ʼ��
//	//time_t(�����ͣ� time(time_t *time)
//	ret = rand()%100+1;//����1~100��������
//	//2.������
//	while (1)
//	{
//		printf("�������:>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´���\n");
//		}
//		else if (guess < ret)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶�������\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//��ǿ��ת��Ϊ���ͣ�time����ָ�룩
//	do
//	{
//		menu(); 
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//goto���--����ת����
//�׳���bug��Ӧ�ó�������
//int main()
//{
//again:
//	printf("hello uic\n");
//	goto again;//���ص���again������ѭ����
//	return 0;
//}
//Ӧ��--�ػ�����
//#include<Windows.h>//����system
//#include<iostream>
////#include<string.h>
//int main()
//{
//	//	char input[20] = { 0 };
//	//	//shutdown -s -t 60(cmd��������60s��ػ���
//	//	system("shutdown -s -t 3600");
//	//again:
//	//	printf("��ע�⣬��ĵ��Խ���1h��ػ���������룺cancel��ȡ���ػ�\n������:>");
//	//	scanf("%s", input);
//	//	if (strcmp(input,"cancel")==0)
//	//	{
//	//		system("shutdown -a");
//	//	}
//	//	else
//	//	{
//	//		goto again;
//	//	}
//
//	//char ch;
//	//int count = 0;
//	//while (scanf("%c", &ch)&&ch!='\n')//T or F
//	//{
//	//	count += (ch == 'c');
//
//	//}
//
//	//printf("%d", count);
//	float a = 10.56;
//	int b = a;
//	printf("%d\n", b);
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define max_times 3
//
//struct login {
//    char user_name[50]; //�û���
//    char password[50];  // ����
//};
//
//int main() {
//    char username[50];
//    char password[50];
//    int times;
//
//    // ���ļ�����ȡ
//    FILE* file = fopen("account.txt", "r");
//    if (file == NULL) {
//        printf("File not found.\n");
//        return 1;
//    }
//
//    for (times = 0; times < max_times; times++) {
//        // ��ʾ�û������û���������
//        printf("Enter username: ");
//        scanf("%s", username);
//        printf("Enter password: ");
//        scanf("%s", password);
//
//        // ÿ�ε�¼����֮ǰ���¶�λ�ļ�ָ�뵽�ļ���ͷ
//        rewind(file);
//
//        struct login Stu;
//        int found = 0; // ����Ƿ��ҵ�ƥ����û���������
//
//        // ���ļ��ж�ȡÿһ���û���������
//        while (fscanf(file, "%s %s", Stu.user_name, Stu.password) == 2) {
//            // ����û����������Ƿ�ƥ��
//            if (strcmp(username, Stu.user_name) == 0 && strcmp(password, Stu.password) == 0) {
//                printf("Login successful! Welcome to the system.\n");
//                fclose(file);
//                return 0; // ��¼�ɹ����˳�����
//            }
//        }
//
//        printf("Invalid account name or password!\n");
//    }
//
//    fclose(file);
//    return 1;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    char ch[] = "world";
//    const char* p;
//    p = "hello";
//    cout << p <<" " << ch << endl;
//    printf("hello world\n");
//    printf("%s ", p);
//    printf("%s\n", ch);
//    return 0;
//} 

//ͷ�ļ�
/*
�ⶼ��
ע��
*/
#include <stdio.h>
//int float double char bool
//int main() {
//	int i = 5;
//	short s = 9;
//	long l = 90;
//	long long lm = 9000000;
//
//	float f = 6.0;
//	double df = 9.0000;
//	bool m = false;
//	char ch = 'k';
//	char c = 98;
//	printf("%c", c);
//	return 0;
//
//}

//int main() {//c���������������
//
//	int n = 9;
//
//	return 0;//��ʾc���Խ����ı�־��Ҳ���Ա�������ϳ����ܷ���ȷ���еı�־
//}

int add(int a, int b)//a��b����ʽ�������βΣ�
{



	return a + b;// the type of return value can and only can be integer
}

int main() {
	int i = 9;
	int m = 8;
	scanf("%d %d", &i, &m);
	int n = add(i, m);
	int j = add(34, 89);
	printf("The sum of i and m is:%d, and the value of j is:%d", add(i,m), j);//��׼�����
	return 0;
}