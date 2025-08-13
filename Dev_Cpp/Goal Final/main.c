//完成最后项目后删除中文注释
//为方便完成项目，以中文注释为主；为使整个工程可读性更高，方便老师阅读，必须要有英文注释
//我（乔奕畅）将整个工程目前分为四个源文件和一个头文件，在相应文件内实现所需功能，不要在main主程序里做子程序的任务。
// 因为目前对代码量不很清楚，所以我可能拆分有些过多，这个后续考虑，为了保证分工，拆分多一些更有利。
//完成过程中应统一ide，以保证项目不会出错，最后再全部放到pelles c上测试
//不同编译器在编译代码时可能会做不一样的处理，为保证跨平台性，所用函数必须在c语言标准库内，若使用ai应注意这一点
//建议使用visual studio，因为可以实现多人线上协同编辑，且有自动缩进，提示，尤其所做子程序较多时，vs的自动提示可以保证输入的准确性
//vs是企业做大项目所用的ide，专业性强，功能多样强大，相比pelles c效率会高出非常多，所写程序更加严谨，个人比较推荐
//在写程序发现bug时，可以在某些可疑语句后加printf语句寻找问题，每个子程序应该能独立运行，可以独立调试。
//若有其他问题可直接在群里交流
// 国际大论坛，几乎所有程序问题都可以解决：https://github.com/
// 查栈溢出及各种偏门问题：https://stackoverflow.co/
// 国内程序员论坛，近几年质量下降：https://www.csdn.net/
// c++标准库官网，包含了所有的c标准库：https://en.cppreference.com/
// vs社区版下载官网：https://visualstudio.microsoft.com/zh-hans/
//ATTENTION：写代码必须要写注释，尤其在实现较复杂功能的地方！

//主程序所在文件，main函数实现的地方，若最后其他文件代码较少可以合并。
#include"head.h"


int main()
{
	while (1)
	{
		MainMenu();
		printf("Enter a number and choose an choiceation:");
		int choice;
		scanf("%d", &choice);
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
			printf("Exit programme\n");
			return 1;
		default:
			break;
		}
	}
	return 0;
}
