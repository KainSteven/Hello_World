
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#include<time.h>
#pragma comment(lib,"winmm.lib")




//以下是函数声明
void out_meum();//游戏菜单函数
void StartGame();//开始游戏主函数
void initGame(int* time, int* distance, int* level, int* life);

int AlphaLife(int time, int distance, int* score, int* life);//字母的生命周期
void showAlpha(char alpha);//显示字符主函数
char createAlpha();//随机创造一个字母函数
int dropAlpha(int x, int* y, char alpha, int time, int distance);//字母的掉落
void flashScreen();//刷新屏幕
void out_help();//帮助函数
void about_Game();//关于游戏
void QuitGame();//退出游戏
int MarchAlpha(char ch,char alpha);//匹配字母
