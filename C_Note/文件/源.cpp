#pragma once
#include<stdio.h>

/*�ļ�������
* 1.�����ļ���Դ�����ļ�.c��Ŀ���ļ���windows������׺Ϊ.obj������ִ�г���windows������׺Ϊ.exe��
* 2.�����ļ�����������ʱ��д�����ݣ��������������Ҫ���ж�ȡ���ݵ��ļ�������������ݵ��ļ���
*/
//�����ļ����ı��ļ����������ļ�
// �������ڴ����Զ����ƴ洢���������ת�������뵽�����ļ��У����Ƕ������ļ���
// ���Ҫ�����������ASCII����ʽ�洢������Ҫ�ڴ洢ǰת������ASCII�ַ�����ʽ�洢���ļ������ı��ļ���
//
//int main()
//{
//	int n = 0;
//	printf("%d\n", n);
//	scanf("%d", &n);
//	printf("%d\n", n);
//	return 0;
//}

int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	if (pf==NULL)
	{
		perror("fopen");
		return 1;
	}
	fwrite(&a, 4, 1, pf);
	fclose(pf);
	pf = NULL;
	return 0;
}
