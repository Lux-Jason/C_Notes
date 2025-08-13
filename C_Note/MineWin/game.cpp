#include"game.h"
void Expand_Find(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* count);

void Init_Board(char board[ROWS][COLS], int rows, int cols, char set)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void Display_Board(char board[ROWS][COLS], int row, int col)
{
    for (int i = 0; i <= row; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (int j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void Set_Mine(char board[ROWS][COLS], int row, int col)
{
    for (int i = 0; i < Easy_Count; i++)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (board[x][y] == '0')
            board[x][y] = '1';
        else
            i--;
    }
}

static int Get_Mine_Count(char board[ROWS][COLS], int x, int y)
{
    return board[x - 1][y] + board[x - 1][y + 1] +
        board[x - 1][y - 1] + board[x][y + 1] +
        board[x][y - 1] + board[x + 1][y + 1] +
        board[x + 1][y] + board[x + 1][y - 1] - 8 * '0';
}

//void Find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//    int x, y, count = 0;
//    while (1)
//    {
//        printf("����������:");
//        scanf("%d %d", &x, &y);;
//        if (x >= 1 && x <= row && y >= 1 && y <= col)
//        {
//            if (mine[x][y] == '0')
//            {
//                count++;
//                show[x][y] = Get_Mine_Count(mine, x, y) + '0';
//                Display_Board(show, ROW, COL);
//            }
//            else
//            {
//                printf("�飬�㱻ը���ˣ�\n");
//                Display_Board(mine, ROW, COL);
//                break;
//            }
//            if (count == ROW * COL - Easy_Count)
//            {
//                printf("��Ӯ�ˣ�\n");
//                break;
//            }
//        }
//        else
//            printf("����Ƿ����������룡\n");
//    }
//}
void Find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x, y, count = 0;
    while (1)
    {
        printf("����������:");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] == '0')
            {
                Expand_Find(mine, show, x, y, &count);//ԭ�����У���Ϊһ��
                Display_Board(show, ROW, COL);
            }
            else
            {
                printf("�飬�㱻ը���ˣ�\n");
                Display_Board(mine, ROW, COL);
                break;
            }
            if (count == ROW * COL - Easy_Count)
            {
                printf("��Ӯ�ˣ�\n");
                break;
            }
        }
        else
            printf("����Ƿ����������룡\n");
    }
}
void Expand_Find(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* count)
{
    if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
    {
        if (Get_Mine_Count(mine, x, y) == 0 && show[x][y] == '#') // �ж�show��#����Ȼ����ѭ��
        {
            show[x][y] = '0';
            (*count)++;
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (i != 0 || j != 0) // i��j����ͬʱΪ0��i������0��j������0��������&&
                        Expand_Find(mine, show, x + i, y + j, count);
                }
            }
        }
        else
        {
            if (show[x][y] == '#') // �ж�show��#���ٸĲ�Ȼ���ظ��ö�Σ�����count�Ӷ�
            {
                show[x][y] = Get_Mine_Count(mine, x, y) + '0';
                (*count)++;
            }
        }
    }
}