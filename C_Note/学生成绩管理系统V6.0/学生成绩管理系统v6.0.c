#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*用到的函数*/
void fun();
void PAUSE();
struct LINK *READ(struct LINK *head);
int Count(struct LINK *head);
void SUM_AND_AVE_COURSE(struct LINK *head);
void SUM_AND_AVE_STU(struct LINK *head);
void SCORE_DECENDING(struct LINK *head);
void SCORE_ASCENDING(struct LINK *head);
void ID_ASCENDING(struct LINK *head);
void ORDER_PRINT(struct LINK *head);
void DICTIONARY_ORDER(struct LINK *head);
void ID_SEARCH(struct LINK *head);
void NAME_SEARCH(struct LINK *head);
void STATISTIC_ANALYSIS(struct LINK *head);
void LIST_RECORD(struct LINK *head);
void SUM_AND_AVE_COURSE_PRINT(struct LINK *head);
void WRITE_FILE(struct LINK *head);
void READ_FILE(struct LINK *head);
void PRINT(struct LINK *head);
void DELETE(struct LINK *head);
void CORRECT(struct LINK *head);

/*全局变量*/
double sum1,sum2,sum3;
double aver1,aver2,aver3;

/*结构体*/
struct LINK
{
    int ranking;
    char name[20],ID[20];
    double yuwen,shuxue,waiyu,sum;
    struct LINK  *next;
};
typedef struct STUDENT
{
    int no;
    char na[20],num[20];
    double yw,sx,wy,ss;
}STU;

/*主函数*/
//int main()
//{
//    printf("\n\n\n\n\n\n\t\t--\tWelcome to use the Student Achievement Management System  \t--\n\n\n\t\t\t\t\t\t\t\t\t\t---Designed by Wang Qixing\n");
//    PAUSE();
//    system("cls");
//    fun();
//    PAUSE();
//    return 0;
//}

/*综合功能函数*/
void fun()
{
    int a;
    char c;
    struct LINK *head=NULL;//链表头节点初始化
    while(1)
    {
        printf("\n\t\t--\tWelcome to use the Student Achievement Management System  \t--\n");
        printf("\t----------------------------------------------------------------------------------------------\t\n");
        printf("\t\t\t1.Input records.\n\n");
        printf("\t\t\t2.Calculate total and average score of every course.\n\n");
        printf("\t\t\t3.Calculate total and average score of every student.\n\n");
        printf("\t\t\t4.Sort in descending order by total score of every student.\n\n");
        printf("\t\t\t5.Sort in ascending order by total score of every student.\n\n");
        printf("\t\t\t6.Sort in ascending order by number.\n\n");
        printf("\t\t\t7.Sort in dictionary order by name.\n\n");
        printf("\t\t\t8.Search by number.\n\n");
        printf("\t\t\t9.Search by name.\n\n");
        printf("\t\t\t10.Statistic analysis for every course.\n\n");
        printf("\t\t\t11.List record.\n\n");
        printf("\t\t\t12.Write to a file.\n\n");
        printf("\t\t\t13.Read from a file.\n\n");
        printf("\t\t\t*14.Edit records.\n\n");
        printf("\t\t\t0.Exit.\n\n");
        printf("\t----------------------------------------------------------------------------------------------\t\n");
        printf("\t\t\tPlease enter your choice:");
        scanf("%d",&a);
        getchar();
        if(a>14||a<0)
        {
            system("cls");
            printf("\n\n\nError!Please try again!\n");
            PAUSE();
            continue;
        }
        switch(a)
        {
        case 0:
            system("cls");
            printf("\n\t\t\tThanks for your use!\n\n");
            PAUSE();
            exit(0);
        case 1:
            system("cls");
            head=READ(head);
            printf("Do you want to input record now?(y/n)\n");
            scanf(" %c",&c);
            while(c=='Y'||c=='y')
            {
                head=READ(head);
                printf("Do you want to input record now?(y/n)\n");
                scanf(" %c",&c);
            }
            getchar();
            SCORE_DECENDING(head);
            PAUSE();
            system("cls");
            break;
        case 2:
            system("cls");
            SUM_AND_AVE_COURSE(head);
            SUM_AND_AVE_COURSE_PRINT(head);
            PAUSE();
            system("cls");
            break;
        case 3:
            system("cls");
            SUM_AND_AVE_STU(head);
            PAUSE();
            system("cls");
            break;
        case 4:
            system("cls");
            SCORE_DECENDING(head);
            ORDER_PRINT(head);
            PAUSE();
            system("cls");
            break;
        case 5:
            system("cls");
            SCORE_ASCENDING(head);
            ORDER_PRINT(head);
            PAUSE();
            system("cls");
            break;
        case 6:
            system("cls");
            ID_ASCENDING(head);
            ORDER_PRINT(head);
            PAUSE();
            system("cls");
            break;
        case 7:
            system("cls");
            DICTIONARY_ORDER(head);
            ORDER_PRINT(head);
            PAUSE();
            system("cls");
            break;
        case 8:
            system("cls");
            ID_SEARCH(head);
            PAUSE();
            system("cls");
            break;
        case 9:
            system("cls");
            NAME_SEARCH(head);
            PAUSE();
            system("cls");
            break;
        case 10:
            system("cls");
            STATISTIC_ANALYSIS(head);
            PAUSE();
            system("cls");
            break;
        case 11:
            system("cls");
            LIST_RECORD(head);
            PAUSE();
            system("cls");
            break;
        case 12:
            system("cls");
            WRITE_FILE(head);
            PAUSE();
            system("cls");
            break;
        case 13:
            system("cls");
            READ_FILE(head);
            PAUSE();
            system("cls");
            break;
        case 14:
            system("cls");
            int flag=0;
            while(1)
            {
                int i;
                if(flag==1)
                {
                    break;
                }
                printf("\n\t\t--\tEdit records.  \t--\n");
                printf("\t----------------------------------------------------------------------------------------------\t\n");
                printf("\t\t\t1.Continue input records.\n\n");
                printf("\t\t\t2.Delete records.\n\n");
                printf("\t\t\t3.Correct records.\n\n");
                printf("\t\t\t0.Return.\n\n");
                printf("\t\t\tPlease enter your choice:");
                scanf("%d",&i);
                if(i>3||i<0)
                {
                    system("cls");
                    printf("\n\n\nError!Please try again!\n");
                    PAUSE();
                    continue;
                }
                switch(i)
                {
                    case 1:
                        system("cls");
                        PRINT(head);
                        printf("Please continue input records!\n\n");
                        head=READ(head);
                        printf("Do you want to input record now?(y/n)\n");
                        scanf(" %c",&c);
                        while(c=='Y'||c=='y')
                        {
                            head=READ(head);
                            printf("Do you want to input record now?(y/n)\n");
                            scanf(" %c",&c);
                        }
                        getchar();
                        SCORE_DECENDING(head);
                        PAUSE();
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        PRINT(head);
                        char c;
                        do
                        {
                            DELETE(head);
                            PRINT(head);
                            printf("Continue delete?(y/n)");
                            scanf(" %c",&c);
                        }while(c=='y'||c=='Y');
                        getchar();
                        PAUSE();
                        system("cls");
                        break;
                    case 3:
                        system("cls");
                        PRINT(head);
                        char ch;
                        do
                        {
                            CORRECT(head);
                            printf("Continue correct?(y/n)");
                            scanf(" %c",&ch);
                        }while(ch=='y'||ch=='Y');
                        getchar();
                        PAUSE();
                        system("cls");
                        break;
                    case 0:
                        system("cls");
                        flag=1;
                        break;
                }
            }
            system("cls");
            break;
        }
    }
}
/*统计节点*/
int Count(struct LINK *head)
{
    int i=0;
    struct LINK *p=head;
    do
    {
        p=p->next;
        i++;
    }while(p->next!=NULL);
    return i;
}
/*输入信息*/
struct LINK *READ(struct LINK *head)
{
    struct LINK *p=NULL,*pr=head;
    p=(struct LINK *)malloc(sizeof(struct LINK));
    if(head==NULL)
    {
        head=p;
        head->next=NULL;
        return head;
    }
    else
    {
        while(pr->next!=NULL)
        {
            pr=pr->next;
        }
        pr->next=p;
        p->next=NULL;
        getchar();
        printf("Please enter student ID:");
        gets(p->ID);
        printf("Please enter student name:");
        gets(p->name);
        printf("Please enter the Chinese score:");
        scanf("%lf",&p->yuwen);
        printf("Please enter the Math score:");
        scanf("%lf",&p->shuxue);
        printf("Please enter the English score:");
        scanf("%lf",&p->waiyu);
        p->sum=p->yuwen+p->shuxue+p->waiyu;
    }
    return head;
}
/*计算每门课的总分和平均分*/
void SUM_AND_AVE_COURSE(struct LINK *head)
{
    if(head==NULL)
    {
        return;
    }
    int n=Count(head);
    struct LINK *p1=head->next;
    sum1=p1->yuwen;
    while(p1->next!=NULL)
    {
        p1=p1->next;
        sum1=sum1+p1->yuwen;
    }
    aver1=sum1/n;
    struct LINK *p2=head->next;
    sum2=p2->shuxue;
    while(p2->next!=NULL)
    {
        p2=p2->next;
        sum2=sum2+p2->shuxue;
    }
    aver2=sum2/n;
    struct LINK *p3=head->next;
    sum3=p3->waiyu;
    while(p3->next!=NULL)
    {
        p3=p3->next;
        sum3=sum3+p3->waiyu;
    }
    aver3=sum3/n;
}
/*打印每门课的总分和平均分*/
void SUM_AND_AVE_COURSE_PRINT(struct LINK *head)
{
    if(head==NULL)
    {
        printf("You have not input record yet!\n");
        return;
    }
    int n=Count(head);
    printf("\n\n\n\n|\tSubject\t\t|\tTotal Score\t|   Ave Score\t|\n\n");
    printf("|\tChinese\t\t|\t%10.1f\t|%10.1f\t|\n",sum1,sum1/n);
    printf("|\tMath\t\t|\t%10.1f\t|%10.1f\t|\n",sum2,sum2/n);
    printf("|\tEnglish\t\t|\t%10.1f\t|%10.1f\t|\n",sum3,sum3/n);
}
/*计算每个学生的总分和平均分*/
void SUM_AND_AVE_STU(struct LINK *head)
{
    struct LINK *p=head;
    if(head==NULL)
    {
        printf("You have not input record yet!\n");
        return;
    }
    printf("\n\n\n\n|      ID \t|\t    Name\t| Chinese\t| Maths\t| English\t| Total\t| Ave\t|\n\n");
    do
    {
        p=p->next;
        printf("|%10s\t|%15s\t| %4.1f\t\t| %4.1f\t| %4.1f\t\t| %4.1f\t| %5.1f\t|\t\t\n",p->ID,p->name,p->yuwen,p->shuxue,p->waiyu,p->sum,p->sum/3);
    }while(p->next!=NULL);
}
/*按每个学生的总分降序排列*/
void SCORE_DECENDING(struct LINK *head)
{
    if(head==NULL)
        return;
    struct LINK *pr=head;
    int n=Count(head);
    double temp;
    char temp1[20];
    for(int i=0;i<n;i++)
    {
        pr=pr->next;
        struct LINK *p=head;
        for(int j=0;j<i;j++)
        {
            p=p->next;
            if(p->sum<pr->sum)
            {
                strcpy(temp1,p->ID);
                strcpy(p->ID,pr->ID);
                strcpy(pr->ID,temp1);
                temp=p->yuwen;
                p->yuwen=pr->yuwen;
                pr->yuwen=temp;
                temp=p->shuxue;
                p->shuxue=pr->shuxue;
                pr->shuxue=temp;
                temp=p->waiyu;
                p->waiyu=pr->waiyu;
                pr->waiyu=temp;
                temp=p->sum;
                p->sum=pr->sum;
                pr->sum=temp;
                strcpy(temp1,p->name);
                strcpy(p->name,pr->name);
                strcpy(pr->name,temp1);
            }
        }
    }
    pr=head->next;
    for(int i=1;i<=n;i++)
    {
        pr->ranking=i;
        pr=pr->next;
    }
}
/*按每个学生的总分升序排列*/
void SCORE_ASCENDING(struct LINK *head)
{
    if(head==NULL)
        return;
    struct LINK *pr=head;
    int n=Count(head);
    double temp;
    char temp1[20];
    for(int i=0;i<n;i++)
    {
        pr=pr->next;
        struct LINK *p=head;
        for(int j=0;j<i;j++)
        {
            p=p->next;
            if(p->sum>pr->sum)
            {
                temp=p->ranking;
                p->ranking=pr->ranking;
                pr->ranking=temp;
                strcpy(temp1,p->ID);
                strcpy(p->ID,pr->ID);
                strcpy(pr->ID,temp1);
                temp=p->yuwen;
                p->yuwen=pr->yuwen;
                pr->yuwen=temp;
                temp=p->shuxue;
                p->shuxue=pr->shuxue;
                pr->shuxue=temp;
                temp=p->waiyu;
                p->waiyu=pr->waiyu;
                pr->waiyu=temp;
                temp=p->sum;
                p->sum=pr->sum;
                pr->sum=temp;
                strcpy(temp1,p->name);
                strcpy(p->name,pr->name);
                strcpy(pr->name,temp1);
            }
        }
    }
}
/*按学号升序排列*/
void ID_ASCENDING(struct LINK *head)
{
    if(head==NULL)
        return;
    struct LINK *pr=head;
    int n=Count(head);
    double temp;
    char temp1[20];
    for(int i=0;i<n;i++)
    {
        pr=pr->next;
        struct LINK *p=head;
        for(int j=0;j<i;j++)
        {
            p=p->next;
            if(strcmp(p->ID,pr->ID)>0)
            {
                temp=p->ranking;
                p->ranking=pr->ranking;
                pr->ranking=temp;
                strcpy(temp1,p->ID);
                strcpy(p->ID,pr->ID);
                strcpy(pr->ID,temp1);
                temp=p->yuwen;
                p->yuwen=pr->yuwen;
                pr->yuwen=temp;
                temp=p->shuxue;
                p->shuxue=pr->shuxue;
                pr->shuxue=temp;
                temp=p->waiyu;
                p->waiyu=pr->waiyu;
                pr->waiyu=temp;
                temp=p->sum;
                p->sum=pr->sum;
                pr->sum=temp;
                strcpy(temp1,p->name);
                strcpy(p->name,pr->name);
                strcpy(pr->name,temp1);
            }
        }
    }
}
/*按字典顺序排列*/
void DICTIONARY_ORDER(struct LINK *head)
{
    if(head==NULL)
        return;
    struct LINK *pr=head;
    int n=Count(head);
    double temp;
    char temp1[20];
    for(int i=0;i<n;i++)
    {
        pr=pr->next;
        struct LINK *p=head;
        for(int j=0;j<i;j++)
        {
            p=p->next;
            if(strcmp(p->name,pr->name)>0)
            {
                temp=p->ranking;
                p->ranking=pr->ranking;
                pr->ranking=temp;
                strcpy(temp1,p->ID);
                strcpy(p->ID,pr->ID);
                strcpy(pr->ID,temp1);
                temp=p->yuwen;
                p->yuwen=pr->yuwen;
                pr->yuwen=temp;
                temp=p->shuxue;
                p->shuxue=pr->shuxue;
                pr->shuxue=temp;
                temp=p->waiyu;
                p->waiyu=pr->waiyu;
                pr->waiyu=temp;
                temp=p->sum;
                p->sum=pr->sum;
                pr->sum=temp;
                strcpy(temp1,p->name);
                strcpy(p->name,pr->name);
                strcpy(pr->name,temp1);
            }
        }
    }
}
/*按顺序打印*/
void ORDER_PRINT(struct LINK *head)
{
    if(head==NULL)
    {
        printf("You have not input record yet!\n");
        return;
    }
    struct LINK *p=head;
    printf("\n\n\n\n| ranking\t|\tID\t|\t    Name\t| Chinese\t| Maths\t| English\t| Total\t|\n\n");
    do
    {
        p=p->next;
        printf("| %5d%\t\t|%10s\t|%15s\t| %4.1f\t\t| %4.1f\t| %4.1f\t\t| %5.1f\t|\n",p->ranking,p->ID,p->name,p->yuwen,p->shuxue,p->waiyu,p->sum);
    }while(p->next!=NULL);
}
/*按学号查找*/
void ID_SEARCH(struct LINK *head)
{
    if(head==NULL)
    {
        printf("You have not input record yet!\n");
        return;
    }
    char c;
    do
    {
        char n[20];
        struct LINK *p=head;
        printf("\nPlease enter the student ID:");
        scanf("%s",n);
        while(strcmp(p->ID,n)!=0&&p->next!=NULL)
        {
            p=p->next;
        }
        if(p->next!=NULL)
            printf("\n\t\tID:%s\n\n\t\tname:%s\n\n\t\tRanking:%d\n\n\t\tChinese:%.1f\n\n\t\tMaths:%.1f\n\n\t\tEnglish:%.1f\n\n\t\tTotal:%.1f\n\n\n",n,p->name,p->ranking,p->yuwen,p->shuxue,p->waiyu,p->sum);
        else
        {
            if(strcmp(p->ID,n)==0)
                printf("\n\t\tID:%s\n\n\t\tname:%s\n\n\t\tRanking:%d\n\n\t\tChinese:%.1f\n\n\t\tMaths:%.1f\n\n\t\tEnglish:%.1f\n\n\t\tTotal:%.1f\n\n\n",n,p->name,p->ranking,p->yuwen,p->shuxue,p->waiyu,p->sum);
            else
                printf("\nError\n\n\n");
        }
        printf("\nContinue search?(y/n)");
        scanf(" %c",&c);
        getchar();
    }while(c=='Y'||c=='y');
}
/*按姓名查找*/
void NAME_SEARCH(struct LINK *head)
{
    if(head==NULL)
    {
        printf("You have not input record yet!\n");
        return;
    }
    char c;
    do
    {
        char name[20];
        struct LINK *p=head;
        printf("\nPlease enter the student name:");
        gets(name);
        while(strcmp(p->name,name)!=0&&p->next!=NULL)
        {
            p=p->next;
        }
        if(p->next!=NULL)
            printf("\n\t\tID:%s\n\n\t\tname:%s\n\n\t\tRanking:%d\n\n\t\tChinese:%.1f\n\n\t\tMaths:%.1f\n\n\t\tEnglish:%.1f\n\n\t\tTotal:%.1f\n\n\n",p->ID,p->name,p->ranking,p->yuwen,p->shuxue,p->waiyu,p->sum);
        else
        {
            if(strcmp(p->name,name)==0)
                printf("\n\t\tID:%s\n\n\t\tname:%s\n\n\t\tRanking:%d\n\n\t\tChinese:%.1f\n\n\t\tMaths:%.1f\n\n\t\tEnglish:%.1f\n\n\t\tTotal:%.1f\n\n\n",p->ID,p->name,p->ranking,p->yuwen,p->shuxue,p->waiyu,p->sum);
            else
                printf("\nError\n\n\n");
        }
        printf("\nContinue search?(y/n)");
        scanf(" %c",&c);
        getchar();
        }while(c=='Y'||c=='y');
}
/*数据分析*/
void STATISTIC_ANALYSIS(struct LINK *head)
{
        if(head==NULL)
        {
            printf("You have not input record yet!\n");
            return;
        }
        int a,b,c,d,e,n=Count(head);
        struct LINK *p=head;
        printf("|Subject/Rank\t|A(90-100)\t| B(80-89)\t| C(70-79)\t| D(60-69)\t| E(0-59)\t|\n\n");
        a=0;b=0;c=0;d=0;e=0;
        do
        {
            p=p->next;
            if(p->yuwen>=90)
                a++;
            else if(p->yuwen>=80)
                b++;
            else if(p->yuwen>=70)
                c++;
            else if(p->yuwen>=60)
                d++;
            else
                e++;
        }while(p->next!=NULL);
        printf("|Chinese\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|\n",a,a*100.0/n,b,b*100.0/n,c,c*100.0/n,d,d*100.0/n,e,e*100.0/n);
        p=head;
        a=0;b=0;c=0;d=0;e=0;
        do
        {
            p=p->next;
            if(p->shuxue>=90)
                a++;
            else if(p->shuxue>=80)
                b++;
            else if(p->shuxue>=70)
                c++;
            else if(p->shuxue>=60)
                d++;
            else
                e++;
        }while(p->next!=NULL);
        printf("|Maths\t\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|\n",a,a*100.0/n,b,b*100.0/n,c,c*100.0/n,d,d*100.0/n,e,e*100.0/n);
        p=head;
        a=0;b=0;c=0;d=0;e=0;
        do
        {
            p=p->next;
            if(p->waiyu>=90)
                a++;
            else if(p->waiyu>=80)
                b++;
            else if(p->waiyu>=70)
                c++;
            else if(p->waiyu>=60)
                d++;
            else
                e++;
        }while(p->next!=NULL);
        printf("|English\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|%2d/%2.1f%%\t|\n",a,a*100.0/n,b,b*100.0/n,c,c*100.0/n,d,d*100.0/n,e,e*100.0/n);
}
/*输出成绩单*/
void LIST_RECORD(struct LINK *head)
{
    if(head==NULL)
    {
        printf("You have not input record yet!\n");
        return;
    }
    printf("| ranking\t|\tID\t|\t\tName\t\t|\tChinese\t|\tMaths\t|\tEnglish\t|\tTotal\t|\n\n");
    SUM_AND_AVE_COURSE(head);
    int n=Count(head);
    struct LINK *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
        printf("| %5d\t\t|%10s\t|\t%15s\t\t|%10.1f\t|%10.1f\t|%10.1f\t|%10.1f\t|\n",p->ranking,p->ID,p->name,p->yuwen,p->shuxue,p->waiyu,p->sum);
    }
    printf("\t\tTotal score\t\t\t\t\t|%10.1f\t|%10.1f\t|%10.1f\t|%10.1f\t|\n",aver1*n,aver2*n,aver3*n,(aver1+aver2+aver3)*n);
    printf("\t\tAverage score\t\t\t\t\t|%10.1f\t|%10.1f\t|%10.1f\t|%10.1f\t|\n",aver1,aver2,aver3,(aver1+aver2+aver3)/3);
}
/*写入文件*/
void WRITE_FILE(struct LINK *head)
{
    if(head==NULL)
    {
        printf("You have not input record yet!\n");
        return;
    }
    FILE *fp;
    struct LINK *p=head;
    if((fp=fopen("LIST.txt","w"))==NULL)
    {
        printf("Failure to open LIST.txt!\n");
        exit(0);
    }
    fprintf(fp,"------------------------------------\n\n");
    while(p->next!=NULL)
    {
        p=p->next;
        fprintf(fp,"ID:%s\nName:%s\nRanking:%d\nChinese:%.1f\nMaths:%.1f\nEnglish:%.1f\nTotal:%.1f\n",p->ID,p->name,p->ranking,p->yuwen,p->shuxue,p->waiyu,p->sum);
        fprintf(fp,"------------------------------------\n\n");
    }
    fclose(fp);
    printf("Write to file successfully!\n");
}
/*从文件读入*/
void READ_FILE(struct LINK *head)
{
    if(head==NULL)
    {
        printf("You have not input record yet!\n");
        return;
    }
    STU stu[31];
    FILE *fp;
    if((fp=fopen("LIST.txt","r"))==NULL)
    {
        printf("Failure to open LIST.txt!\n");
        exit(0);
    }
    int n=Count(head);
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"------------------------------------\n\n");
        fscanf(fp,"ID:%s\nName:",stu[i].num);
        fgets(stu[i].na,sizeof(stu[i].na),fp);
        fscanf(fp,"Ranking:%d\nChinese:%lf\nMaths:%lf\nEnglish:%lf\nTotal:%lf\n",&stu[i].no,&stu[i].yw,&stu[i].sx,&stu[i].wy,&stu[i].ss);
    }
    fscanf(fp,"------------------------------------\n\n");
    fclose(fp);
    for(int i=0;i<n;i++)
    {
        printf("------------------------------------\n\n");
        printf("ID:%s\nName:%sRanking:%d\nChinese:%.1f\nMaths:%.1f\nEnglish:%.1f\nTotal:%.1f\n",stu[i].num,stu[i].na,stu[i].no,stu[i].yw,stu[i].sx,stu[i].wy,stu[i].ss);
    }
    printf("------------------------------------\n\n");
}
/*打印*/
void PRINT(struct LINK *head)
{
    if(head==NULL)
    {
        printf("You have not input record yet!\n");
        return;
    }
    struct LINK *p=head;
    int i=0;
    do
    {
        p=p->next;
        i++;
        printf("No.%d\nName:%s\nID:%s\nChinese:%.1f\nMaths:%.1f\nEnglish:%.1f\nTotal:%.1f\nRanking:%d\n",i,p->name,p->ID,p->yuwen,p->shuxue,p->waiyu,p->sum,p->ranking);
        printf("------------------------------------\n");
    }while(p->next!=NULL);
}
/*删除数据*/
void DELETE(struct LINK *head)
{
    int i, Cou;
    int a=1;
    struct LINK *p1=head,*p2=NULL;
    Cou=Count(head);
    printf("\nWhich record do you want to delete?Please input its No. :");
    scanf(" %d",&i);
    if(i<=0||i>Cou)
        printf("Error !!\n");
    else if(i==Cou)
    {
        while(p1->next!=NULL)
        {
            p1=p1->next;
        }
        p2=head;
        while((p2->next)!=p1)
        {
            p2=p2->next;
        }
        p2->next=NULL;
        free(p1);
    }
    else
    {
        while(i!=a)
        {
            p1=p1->next;
            a++;
        }
        p2=p1->next;
        p1->next=p2->next;
        free(p2);
    }
    SCORE_DECENDING(head);
    system("cls");
    printf("Delete record successfully!!\n");
}
/*修改数据*/
void CORRECT(struct LINK *head)
{
    int i, Cou;
    int a=1;
    struct LINK *p=head->next;
    Cou=Count(head);
    printf("\nWhich record do you want to correct?Please input its No. :");
    scanf(" %d",&i);
    getchar();
    if(i<=0||i>Cou)
    {
        printf("Error !!\n");
    }
    else
    {
        while(i!=a)
        {
            p=p->next;
            a++;
        }
        printf("Please input the new name:");
        gets(p->name);
        printf("Please input the new ID:");
        gets(p->ID);
        printf("Please input the new Chinese score:");
        scanf("%lf",&p->yuwen);
        printf("Please input the new Maths score:");
        scanf("%lf",&p->shuxue);
        printf("Please input the new English score:");
        scanf("%lf",&p->waiyu);
        p->sum=p->yuwen+p->shuxue+p->waiyu;
        SCORE_DECENDING(head);
    }
}
/*暂停*/
void PAUSE()
{
    printf("\nPress Enter to continue...");
    getchar();
}
