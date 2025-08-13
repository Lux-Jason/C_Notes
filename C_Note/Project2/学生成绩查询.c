#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct student{
    char number[20];
    char name[20];
    double cj[3];
    double average;
};
void scanfstudent(struct student s[]);//1.输入学生信息 
void average(struct student s[]);//2.查询信息,并计算平均值
void cr(struct student s[]);//3.插入学生信息
void bc(struct student s[]);//4.保存学生信息
void delete1(struct student s[]);//5.删除学生信息
int menu();//菜单  
void scanfstudent(struct student s[])//1.输入学生信息 
{
	int n, i;
	printf("请输入你要输入学生的个数：");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {   struct student *p=(struct student *)malloc(sizeof(struct student));
        printf("请输入该生的学号：");
        scanf("%s",s[i].number);
        printf("请输入该生的姓名：");
        scanf("%s",s[i].name);
        printf("请输入该生的成绩：");
        scanf("%lf%lf%lf", &s[i].cj[0], &s[i].cj[1], &s[i].cj[2]);
		s[i].average = (s[i].cj[0] + s[i].cj[1] + s[i].cj[2]) / 3; 
    }
}
void average(struct student s[])//2.查询信息,并计算平均值 
{
	int i = 0, f=0;
	char ch[50];
	printf("请输入你要查询学生学号：\n");
	scanf("%s", ch);
	for(i=0;i<1000;i++){
		if(strcmp(ch, s[i].number) == 0){
		    s[i].average = (s[i].cj[0] + s[i].cj[1] + s[i].cj[2]) / 3;
		    printf("\n");
		    printf("此同学的基本信息为\n");
		    printf("姓 名: %s\n学 号: %s\n成 绩: %.1lf %.1lf %.1lf\n平 均 成 绩: %.2lf\n", s[i].name, s[i].number, s[i].cj[0], s[i].cj[1], s[i].cj[2], s[i].average);
		    f = 1;
		}
	}
	if(f == 0) printf("没有此学生!\n");	
}
void cr(struct student s[])//3.插入学生信息 
{
    int i, j, flag, n, m;
    printf("已有多少学生：\n");
    scanf("%d", &n);
	i = n;				//n为现有学生人数 
	printf("请输入待增加的学生数:\n");
	scanf("%d",&m);
	if(m>0)
	{
		do
		{
			flag=1;
			while(flag)
			{
				flag=0;
				printf("请输入第%d位学生的学号:",i+1);
				scanf("%s", s[i].number);
				for(j=0;j<i;j++)			/*与之前已有学号比较，如果重复，则置flag为0，重新进入循环体内输入*/
					if(strcmp(s[i].number,s[j].number)==0)
					{
						printf("已有该学号，请检查后重新输入！\n");
						flag=1;
						break;				/*如有重复立即退出该层循环，提高判断速度*/
					}
			}
				printf("请输入第%d位学生的姓名:",i+1);
				scanf("%s", s[i].name);
				printf("请输入第%d位学生的成绩:",i+1);
				 scanf("%lf%lf%lf", &s[i].cj[0], &s[i].cj[1], &s[i].cj[2]);
				s[i].average = (s[i].cj[0] + s[i].cj[1] + s[i].cj[2]) / 3; 
				if(flag==0)			/*与之前已有学生学号无重复，学生人数加1*/
				{
					i++;
				}
		}while(i<n+m);
	}
	n+=m;
	printf("信息增加完毕！\n\n");
}
void bc(struct student s[])//4.保存学生信息 
{
	FILE *fp;
	int i = 0, n=0;
	char ch[]={"\0"};
	if((fp=fopen("C:\\Users\\装作不在意\\Desktop\\student.txt","w"))==NULL)
    {  
        printf("不能打开此文件，请按任意键退出\n");  
        exit(1);  
    }
    while(strcmp(ch, s[i].name) != 0) 
    {  
        fprintf(fp,"%s  %s  %.1lf %.1lf %.1lf  %.2lf \n", s[i].name, s[i].number, s[i].cj[0], s[i].cj[1], s[i].cj[2], s[i].average);
		i++;
		n = 1;
	}
	if(n == 1){
 	   printf("保存成功\n");
	}else{
	   printf("保存失败\n");	
	}
	fclose(fp);   
}
void delete1(struct student s[])//5.删除学生信息 
{
	FILE *fp;
	int i = 0, n=0;
	char ch[50];
	char a[]={0}; 
	printf("请输入要删除的学号");
	scanf("%s", ch);
	if((fp=fopen("C:\\Users\\装作不在意\\Desktop\\student.txt","w")) == NULL)  
    {  
        printf("文件不存在，无法删除\n");  
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
 	   printf("删除成功\n");
	}else{
	   printf("删除失败,没有该学生\n");	
	} 
}
int menu()
{
	int choose;
	do{
		printf("************************\n");
      printf("*****1.输入学生信息*****\n");
      printf("*****2.查询学生信息*****\n");
      printf("*****3.插入学生信息*****\n");
	    printf("*****4.保存学生信息*****\n");
	    printf("*****5.删除学生信息*****\n");
	    printf("*****6.退出系统*********\n");
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
//			printf("感谢你的使用，再见！\n");
//			break;
//		} 
//	}
//return 0;
//}






//1．给设计一种结构体，用来保存学生信息（包括学号、姓名、三科成绩、平均成绩）。除平均成绩外，各项数据均由键盘输入。现在要求输入若干学生的信息，并实现以下功能：（可以使用数组或链表实现）
//1）计算学生的平均成绩，并填入相应的数据域；
//2）插入学生；
//3）删除学生；
//4）查询学生。

//选择， 循环，数组， 结构体，综合题 

//stu[5].xh  struct student *p; p =  stu; p = p + 5;  
// (*p).xh ==  stu[5].xh = p -> xh
