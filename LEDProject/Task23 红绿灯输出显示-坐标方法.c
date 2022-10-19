/**
 * @file Task223 红绿灯输出显示-坐标方法.c
 * @brief: 演示知识点：gotoxy(x,y)函数
 * @author: 黄先栋
 * @date: 2022-10-18 22:19:13
 * 
 **/

#include<stdio.h>	//printf()	函数所在库
#include<conio.h> 	//getch()	函数所在库
#include<windows.h>	//system()	函数所在库
#include<unistd.h>	//sleep()	函数所在库

//宏定义前景色
#define RED 12
#define YLW 14
#define GRN 2

//COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。
/*其原型为：
  typedef struct _COORD {
  SHORT X; // 横坐标
  SHORT Y; // 纵坐标
  } COORD; */

//符号定位函数（汉字占2个字符宽度）
void gotoxy(short y, short x)  //列、行。左上角为(0,0)
{
	COORD coord = {y, x};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color(int colour){  //为了书写方便、含义明确
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour); 
}
void hideCursor(){  //隐藏光标，减少光标对视觉的影响
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void init(){  		//初始化
	hideCursor();
	color(2);		//绿色：0x2
	printf("●"); 
	color(14);		//黄色：0xE
	printf("●"); 
	color(12);		//红色：0xC
	printf("●"); 
}
void red(){
	system("cls");
//	printf("\r");	//回车即回到行首，继续输出则会覆盖本行原有内容
	gotoxy(4,0);
//	color(GRN);printf("○");	
//	color(YLW);printf("○");
	color(RED);printf("●");
}
void ylwFill(){
	system("cls");
//	printf("\r");
	gotoxy(2,0);
//	color(GRN);printf("○");	
	color(YLW);printf("●");
//	color(RED);printf("○");
}
void ylwEmpty(){
//	system("cls");
//	printf("\r");
	gotoxy(2,0);
//	color(GRN);printf("○");	
	color(YLW);printf("○");
//	color(RED);printf("○");
}
void grn(){
	system("cls");
	gotoxy(0,0);
	color(GRN);printf("●");	
//	color(YLW);printf("○");
//	color(RED);printf("○");
}

int main(){
	//system()用于执行DOS(windows系统)或shell(Linux/Unix系统)命令
	system("color 0F\n");//黑色背景
	/*  颜色由两个十六进制数字指定，左边为背景色，右边为前景色
	  0 = 黑色       8 = 灰色
	  1 = 蓝色       9 = 淡蓝色
	  2 = 绿色       A = 淡绿色
	  3 = 湖蓝色     B = 淡浅绿色
	  4 = 红色       C = 淡红色
	  5 = 紫色       D = 淡紫色
	  6 = 黄色       E = 淡黄色
	  7 = 白色       F = 亮白色 
	 */
	//局部颜色设置，前景色与背景色与DOS相同，各占4bit。可单独设置前景色。
	init();	sleep(2); //上电初始化2秒
	while(1){
		grn();sleep(8);	//绿灯8秒
		for(int i=0;i<3;i++){//黄灯闪3秒
			ylwFill();Sleep(500);
			ylwEmpty();Sleep(500);
		}		
		red();sleep(5);	//红灯5秒
	}	
	return 0;
}

