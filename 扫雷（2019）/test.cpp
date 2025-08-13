 #include"Mine_Sweeper.h"

void MENU()
{
	printf("******************************\n");
	printf("*********   1.PLAY   *********\n");
	printf("*********   0.EXIT   *********\n");
	printf("******************************\n");
}

void Game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	CheckMine(mine, show, ROW, COL);
}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		MENU();
		printf("\n请选择程序>>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("\n<退出游戏>\n\n");
			break;
		default:
			printf("\n<选择错误，请重新选择>\n\n");
			break;
		}
	} while (input);
	return 0;
}

