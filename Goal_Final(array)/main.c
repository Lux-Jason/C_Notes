//��������Ŀ��ɾ������ע��
//Ϊ���������Ŀ��������ע��Ϊ����Ϊʹ�������̿ɶ��Ը��ߣ�������ʦ�Ķ�������Ҫ��Ӣ��ע��
//�ң����ȳ�������������Ŀǰ��Ϊ�ĸ�Դ�ļ���һ��ͷ�ļ�������Ӧ�ļ���ʵ�����蹦�ܣ���Ҫ��main�����������ӳ��������
// ��ΪĿǰ�Դ�������������������ҿ��ܲ����Щ���࣬����������ǣ�Ϊ�˱�֤�ֹ�����ֶ�һЩ��������
//��ɹ�����Ӧͳһide���Ա�֤��Ŀ������������ȫ���ŵ�pelles c�ϲ���
//��ͬ�������ڱ������ʱ���ܻ�����һ���Ĵ���Ϊ��֤��ƽ̨�ԣ����ú���������c���Ա�׼���ڣ���ʹ��aiӦע����һ��
//����ʹ��visual studio����Ϊ����ʵ�ֶ�������Эͬ�༭�������Զ���������ʾ�����������ӳ���϶�ʱ��vs���Զ���ʾ���Ա�֤�����׼ȷ��
//vs����ҵ������Ŀ���õ�ide��רҵ��ǿ�����ܶ���ǿ�����pelles cЧ�ʻ�߳��ǳ��࣬��д��������Ͻ������˱Ƚ��Ƽ�
//��д������bugʱ��������ĳЩ���������printf���Ѱ�����⣬ÿ���ӳ���Ӧ���ܶ������У����Զ������ԡ�
//�������������ֱ����Ⱥ�ｻ��
// ���ʴ���̳���������г������ⶼ���Խ����https://github.com/
// ��ջ���������ƫ�����⣺https://stackoverflow.co/
// ���ڳ���Ա��̳�������������½���https://www.csdn.net/
// c++��׼����������������е�c��׼�⣺https://en.cppreference.com/
// vs���������ع�����https://visualstudio.microsoft.com/zh-hans/
//ATTENTION��д�������Ҫдע�ͣ�������ʵ�ֽϸ��ӹ��ܵĵط���

#include"head.h"

void savefile() {
	FILE* file;
	int i, j, k;
	file = fopen("file.txt","w+");
	if (file != NULL) {
		for (i = 0; i < num_Courses; i++) {
			fprintf(file, "%s %s %.2f %d", Course_arr[i].courseID, Course_arr[i].coursename, Course_arr[i].Final, Course_arr[i].data);
			fprintf(file, "\n");
			for (j = 0; j < Course_arr[i].data; j++) {
				fprintf(file, "%s %.2f %.2f %d", Course_arr[i].item[j].name, Course_arr[i].item[j].percentage, Course_arr[i].item[j].maxScore, Course_arr[i].item[j].numOfGrades);
				for (k = 0; k < Course_arr[i].item[j].numOfGrades; k++)
				{
					fprintf(file, "%.2f", Course_arr[i].item[j].grades[k]);
				}
				fprintf(file, "\n");
			}
			fprintf(file, "\n");
		}
		fclose(file);
		printf("Data written to file successfully.\n");
	}
	else
		printf("Error opening file for writing.\n");
}
//void fileout()
//{
//	FILE* file;
//	int i, j, k;
//	file = fopen("file.txt", "w+");
//	if (file != NULL) {
//		for (i = 0; i < num_Courses; i++) {
//			fscanf(file, "%s %s %.2f %d", Course_arr[i].courseID, Course_arr[i].coursename, Course_arr[i].Final, Course_arr[i].data);
//			for (j = 0; j < Course_arr[i].data; j++) {
//				fscanf(file, "%s %.2f %.2f %d", Course_arr[i].item[j].name, Course_arr[i].item[j].percentage, Course_arr[i].item[j].maxScore, Course_arr[i].item[j].numOfGrades);
//				for (k = 0; k < Course_arr[i].item[j].numOfGrades; k++)
//				{
//					fscanf(file, "%.2f", Course_arr[i].item[j].grades[k]);
//				}
//				fscanf(file, "\n");
//			}
//			fprintf(file, "\n");
//		}
//		fclose(file);
//		printf("Data written to file successfully.\n");
//	}
//	else
//		printf("Error opening file for writing.\n");
//}
int charToInt(char c)
{
	switch (c) 
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		return -1;
	}
}
int main()
{
	FILE* pf;
	while (1)
	{
		int choice = MainMenu();
		switch (choice)
		{
		case 1: // Edit Course
			EditCourse();
			break;
		case 2: // Edit Grade 
			EditGrade();
			break;
		case 3: // Expected Final Grade
			ExpectedFinalGrade();
			break;
		case 4: // View Course
			ViewCourse();
			break;
		case 5: // Exit
			savefile();
			printf("Exit programme\n");
			return 0;
		default:
			break;
		}
	}
	return 0;
}