#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct student{
    char number[20];
    char name[20];
    double cj[3];
    double average;
};
void scanfstudent(struct student s[]);//1.����ѧ����Ϣ 
void average(struct student s[]);//2.��ѯ��Ϣ,������ƽ��ֵ
void cr(struct student s[]);//3.����ѧ����Ϣ
void bc(struct student s[]);//4.����ѧ����Ϣ
void delete1(struct student s[]);//5.ɾ��ѧ����Ϣ
int menu();//�˵�  
void scanfstudent(struct student s[])//1.����ѧ����Ϣ 
{
	int n, i;
	printf("��������Ҫ����ѧ���ĸ�����");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {   struct student *p=(struct student *)malloc(sizeof(struct student));
        printf("�����������ѧ�ţ�");
        scanf("%s",s[i].number);
        printf("�����������������");
        scanf("%s",s[i].name);
        printf("����������ĳɼ���");
        scanf("%lf%lf%lf", &s[i].cj[0], &s[i].cj[1], &s[i].cj[2]);
		s[i].average = (s[i].cj[0] + s[i].cj[1] + s[i].cj[2]) / 3; 
    }
}
void average(struct student s[])//2.��ѯ��Ϣ,������ƽ��ֵ 
{
	int i = 0, f=0;
	char ch[50];
	printf("��������Ҫ��ѯѧ��ѧ�ţ�\n");
	scanf("%s", ch);
	for(i=0;i<1000;i++){
		if(strcmp(ch, s[i].number) == 0){
		    s[i].average = (s[i].cj[0] + s[i].cj[1] + s[i].cj[2]) / 3;
		    printf("\n");
		    printf("��ͬѧ�Ļ�����ϢΪ\n");
		    printf("�� ��: %s\nѧ ��: %s\n�� ��: %.1lf %.1lf %.1lf\nƽ �� �� ��: %.2lf\n", s[i].name, s[i].number, s[i].cj[0], s[i].cj[1], s[i].cj[2], s[i].average);
		    f = 1;
		}
	}
	if(f == 0) printf("û�д�ѧ��!\n");	
}
void cr(struct student s[])//3.����ѧ����Ϣ 
{
    int i, j, flag, n, m;
    printf("���ж���ѧ����\n");
    scanf("%d", &n);
	i = n;				//nΪ����ѧ������ 
	printf("����������ӵ�ѧ����:\n");
	scanf("%d",&m);
	if(m>0)
	{
		do
		{
			flag=1;
			while(flag)
			{
				flag=0;
				printf("�������%dλѧ����ѧ��:",i+1);
				scanf("%s", s[i].number);
				for(j=0;j<i;j++)			/*��֮ǰ����ѧ�űȽϣ�����ظ�������flagΪ0�����½���ѭ����������*/
					if(strcmp(s[i].number,s[j].number)==0)
					{
						printf("���и�ѧ�ţ�������������룡\n");
						flag=1;
						break;				/*�����ظ������˳��ò�ѭ��������ж��ٶ�*/
					}
			}
				printf("�������%dλѧ��������:",i+1);
				scanf("%s", s[i].name);
				printf("�������%dλѧ���ĳɼ�:",i+1);
				 scanf("%lf%lf%lf", &s[i].cj[0], &s[i].cj[1], &s[i].cj[2]);
				s[i].average = (s[i].cj[0] + s[i].cj[1] + s[i].cj[2]) / 3; 
				if(flag==0)			/*��֮ǰ����ѧ��ѧ�����ظ���ѧ��������1*/
				{
					i++;
				}
		}while(i<n+m);
	}
	n+=m;
	printf("��Ϣ������ϣ�\n\n");
}
void bc(struct student s[])//4.����ѧ����Ϣ 
{
	FILE *fp;
	int i = 0, n=0;
	char ch[]={"\0"};
	if((fp=fopen("C:\\Users\\װ��������\\Desktop\\student.txt","w"))==NULL)
    {  
        printf("���ܴ򿪴��ļ����밴������˳�\n");  
        exit(1);  
    }
    while(strcmp(ch, s[i].name) != 0) 
    {  
        fprintf(fp,"%s  %s  %.1lf %.1lf %.1lf  %.2lf \n", s[i].name, s[i].number, s[i].cj[0], s[i].cj[1], s[i].cj[2], s[i].average);
		i++;
		n = 1;
	}
	if(n == 1){
 	   printf("����ɹ�\n");
	}else{
	   printf("����ʧ��\n");	
	}
	fclose(fp);   
}
void delete1(struct student s[])//5.ɾ��ѧ����Ϣ 
{
	FILE *fp;
	int i = 0, n=0;
	char ch[50];
	char a[]={0}; 
	printf("������Ҫɾ����ѧ��");
	scanf("%s", ch);
	if((fp=fopen("C:\\Users\\װ��������\\Desktop\\student.txt","w")) == NULL)  
    {  
        printf("�ļ������ڣ��޷�ɾ��\n");  
        exit(1);  
    }
    while(strcmp(a, s[i].name) != 0) 
    {  
        if(strcmp(ch, s[i].number) == 0){
		    strcpy(s[i].name,"\0");
		    strcpy(s[i].number,"\0");
		    s[i].cj[0] = 0;
		    s[i].cj[1] = 0;
		    s[i].cj[2] = 0;
		    s[i].average = 0;
			n = 1; 
		}
        fprintf(fp,"%s  %s  %.1lf %.1lf %.1lf  %.2lf \n", s[i].name, s[i].number, s[i].cj[0], s[i].cj[1], s[i].cj[2], s[i].average);
		i++;
	} 
	if(n == 1){
 	   printf("ɾ���ɹ�\n");
	}else{
	   printf("ɾ��ʧ��,û�и�ѧ��\n");	
	} 
}
int menu()
{
	int choose;
	do{
		printf("************************\n");
      printf("*****1.����ѧ����Ϣ*****\n");
      printf("*****2.��ѯѧ����Ϣ*****\n");
      printf("*****3.����ѧ����Ϣ*****\n");
	    printf("*****4.����ѧ����Ϣ*****\n");
	    printf("*****5.ɾ��ѧ����Ϣ*****\n");
	    printf("*****6.�˳�ϵͳ*********\n");
	    printf("************************\n");
	    scanf("%d", &choose);
	}while(choose < 1 || choose > 6);
	return choose; 
}
//int main(){
//	struct student s[1000];
//	int choose;
//	while(1){
//		choose = menu();
//	    switch(choose){
//	    	case 1: scanfstudent(s); break;
//	        case 2: average(s); break;
//	    	case 3: cr(s);break;
//	    	case 4: bc(s);break;
//	    	case 5: delete1(s);break;
//		}
//		if(choose == 6){
//			printf("��л���ʹ�ã��ټ���\n");
//			break;
//		} 
//	}
//return 0;
//}






//1�������һ�ֽṹ�壬��������ѧ����Ϣ������ѧ�š����������Ƴɼ���ƽ���ɼ�������ƽ���ɼ��⣬�������ݾ��ɼ������롣����Ҫ����������ѧ������Ϣ����ʵ�����¹��ܣ�������ʹ�����������ʵ�֣�
//1������ѧ����ƽ���ɼ�����������Ӧ��������
//2������ѧ����
//3��ɾ��ѧ����
//4����ѯѧ����

//ѡ�� ѭ�������飬 �ṹ�壬�ۺ��� 

//stu[5].xh  struct student *p; p =  stu; p = p + 5;  
// (*p).xh ==  stu[5].xh = p -> xh
