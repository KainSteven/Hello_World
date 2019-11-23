#include "MarchAlpha.h"


//以下是函数实现
void out_meum()
{

	printf("\t\t欢迎游玩打字母游戏小程序！\n");
	//mciSendString("open C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
	//mciSendString("play C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
	printf("\t\t以下为游戏菜单：\n");
	printf("\t\t***********************************\n");
	printf("\t\t**-----      1.开始游戏     -----**\n");
	printf("\t\t**-----      2.游戏帮助     -----**\n");
	printf("\t\t**-----      3.关于本游戏   -----**\n");
	printf("\t\t**-----      4.退出游戏     -----**\n");
	printf("\t\t***********************************\n");
	printf("\t\t请选择要执行的操作：\t");
	return;
}

void initGame(int* time, int* distance, int* level,int *life)
{

	printf("请选择游戏难度(1~5)：\t");
	scanf("%d", level);
	getchar();
	switch (*level)
	{
	case 1:*time = 800; *distance = 10; *life = 5; break;
	case 2:*time = 800; *distance = 8; *life = 4; break;
	case 3:*time = 600; *distance = 5; *life = 4; break;
	case 4:*time = 500; *distance = 4; *life = 3; break;
	case 5:*time = 400; *distance = 4; *life = 2; break;
	default:*time = 800; *distance = 10; *life = 5; printf("未正确选择难度，系统将自动设置难度为1！\n"); break;
	}
	Sleep(500);
	printf("难度Level：%d\t", *level);
	Sleep(500);
	printf("\n游戏初始化......\n");
	Sleep(500);
	printf("初始化ing......\n");
	Sleep(500);
	printf("游戏开始！\n");
	Sleep(500);
}

void StartGame()//开始游戏
{
	int time = 0, distance = 0, level = 0, life = 0, score = 0;;
	initGame(&time, &distance, &level,&life);

	while (1)
	{
		AlphaLife(time, distance,&score,&life);
		if (life == 0)
		{
			break;
		}
	}
	printf("您的得分为\t%d\n",score);
	return;
}

int AlphaLife(int time, int distance,int *score,int *life)//一个字母的生命周期（从创建到消失）
{
	char alpha = createAlpha();
	char ch;
	//*score = 0;
	int x = rand() % 30, y = 0;
	//showAlpha(alpha);
	Sleep(time);
	while (1)
	{
		if (_kbhit())
		{
			ch = _getche();
			if (MarchAlpha(ch, alpha) == 1)
			{
				(*score)++;
				break;
			}
			else
			{
				printf("输入了错误的字母！\n");
				(*life)--;
				printf("生命值减一!现在生命值：%d\n", *life);
				break;
			}

		}
		else
		{
			//此处写未键入字母，任由字母下落的函数
			flashScreen();
			if (dropAlpha(x, &y, alpha, time, distance) == 1)
			{
				(*life)--;
				printf("生命值减一!现在生命值：%d\n", *life);
				return 0;
				//break;
			}
		}
	}
	return 0;

}
char createAlpha()//创造字母
{
	srand((unsigned)time(0));
	return 'a' + rand() % 26;
}

int MarchAlpha(char ch, char alpha)
{
	if (ch == alpha)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}

void gotoxy(int x, int y)
{
	COORD loc = { x,y };
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
}

void showAlpha(char alpha)//展示字母
{
	printf("%c\n", alpha);
}

int dropAlpha(int x, int *y, char alpha, int time, int distance)//下落字母
{
	if (*y < distance)
	{
		gotoxy(x, *y);
		showAlpha(alpha);
		(*y)++;
		Sleep(time);
	}
	else if (distance == *y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}


void flashScreen()//刷新屏幕
{
	system("cls");
}

void out_help()//帮助
{
	return;
}

void about_Game()//关于游戏
{
	return;
}

void QuitGame()//退出游戏
{
	return;
}
