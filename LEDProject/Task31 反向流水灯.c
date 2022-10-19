/**
 * @file Task31 反向流水灯.c
 * @brief: 演示知识点：双重循环、循环嵌套、“死”循环
 * @author: 黄先栋
 * @date: 2022-10-18 21:09:13
 * 
 **/

#include<stdio.h>	//printf()	函数所在库
#include<conio.h> 	//getch()	函数所在库
#include<windows.h>	//system()、Sleep(xms)	函数所在库
#include<unistd.h>	//sleep()	函数所在库

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

int main(){
	system("color F4\n");

	gotoxy(10,4);
	printf("反向流水灯：\n");
	hideCursor();

	int i=8;
	while(1)
	{
		gotoxy(10,5);
		for(int j=0; j<i; j++)
		{
			printf("○");
		}
		for(int j=i; j<8; j++)
		{
			printf("●");
		}
		i--;
		if(i==-1)i=8;
		sleep(1);
	}

	return 0;
}

