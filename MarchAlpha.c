#include "MarchAlpha.h"


//�����Ǻ���ʵ��
void out_meum()
{

	printf("\t\t��ӭ�������ĸ��ϷС����\n");
	//mciSendString("open C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
	//mciSendString("play C:\\Users\\user\\Desktop\\1112.mp3", NULL, 0, NULL);
	printf("\t\t����Ϊ��Ϸ�˵���\n");
	printf("\t\t***********************************\n");
	printf("\t\t**-----      1.��ʼ��Ϸ     -----**\n");
	printf("\t\t**-----      2.��Ϸ����     -----**\n");
	printf("\t\t**-----      3.���ڱ���Ϸ   -----**\n");
	printf("\t\t**-----      4.�˳���Ϸ     -----**\n");
	printf("\t\t***********************************\n");
	printf("\t\t��ѡ��Ҫִ�еĲ�����\t");
	return;
}

void initGame(int* time, int* distance, int* level,int *life)
{

	printf("��ѡ����Ϸ�Ѷ�(1~5)��\t");
	scanf("%d", level);
	getchar();
	switch (*level)
	{
	case 1:*time = 800; *distance = 10; *life = 5; break;
	case 2:*time = 800; *distance = 8; *life = 4; break;
	case 3:*time = 600; *distance = 5; *life = 4; break;
	case 4:*time = 500; *distance = 4; *life = 3; break;
	case 5:*time = 400; *distance = 4; *life = 2; break;
	default:*time = 800; *distance = 10; *life = 5; printf("δ��ȷѡ���Ѷȣ�ϵͳ���Զ������Ѷ�Ϊ1��\n"); break;
	}
	Sleep(500);
	printf("�Ѷ�Level��%d\t", *level);
	Sleep(500);
	printf("\n��Ϸ��ʼ��......\n");
	Sleep(500);
	printf("��ʼ��ing......\n");
	Sleep(500);
	printf("��Ϸ��ʼ��\n");
	Sleep(500);
}

void StartGame()//��ʼ��Ϸ
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
	printf("���ĵ÷�Ϊ\t%d\n",score);
	return;
}

int AlphaLife(int time, int distance,int *score,int *life)//һ����ĸ���������ڣ��Ӵ�������ʧ��
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
				printf("�����˴������ĸ��\n");
				(*life)--;
				printf("����ֵ��һ!��������ֵ��%d\n", *life);
				break;
			}

		}
		else
		{
			//�˴�дδ������ĸ��������ĸ����ĺ���
			flashScreen();
			if (dropAlpha(x, &y, alpha, time, distance) == 1)
			{
				(*life)--;
				printf("����ֵ��һ!��������ֵ��%d\n", *life);
				return 0;
				//break;
			}
		}
	}
	return 0;

}
char createAlpha()//������ĸ
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

void showAlpha(char alpha)//չʾ��ĸ
{
	printf("%c\n", alpha);
}

int dropAlpha(int x, int *y, char alpha, int time, int distance)//������ĸ
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


void flashScreen()//ˢ����Ļ
{
	system("cls");
}

void out_help()//����
{
	return;
}

void about_Game()//������Ϸ
{
	return;
}

void QuitGame()//�˳���Ϸ
{
	return;
}
