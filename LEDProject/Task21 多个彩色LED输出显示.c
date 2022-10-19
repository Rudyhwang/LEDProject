/**
 * @file Task21 多个彩色LED输出显示.c 
 * @brief: 演示知识点：C语言最基本框架结构、printf()函数、system()函数、局部颜色控制
 * @author: 黄先栋
 * @date: 2022-10-18 21:09:13
 * 
 **/

#include<stdio.h>	//printf()	函数所在库
#include<conio.h> 	//getch()	函数所在库
#include<windows.h>	//system()	函数所在库
#include<unistd.h>	//sleep()	函数所在库

int main(){
	//system()用于执行DOS(windows系统)或shell(Linux/Unix系统)命令
	system("color 8F\n");
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //淡红色前景
	printf("●"); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xD); //淡紫色前景
	printf("●"); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1E);//蓝色背景+淡黄色前景
	printf("●"); 
	
	return 0;
}

