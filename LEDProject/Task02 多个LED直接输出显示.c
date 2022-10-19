/**
 * @file Task02 多个LED直接输出显示.c 
 * @brief: 演示知识点：顺序结构
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
	system("color F4\n");
/*  颜色由两个十六进制数字指定，左边为背景色，右边为前景色
	  0 = 黑色       8 = 灰色
	  1 = 蓝色       9 = 淡蓝色
	  2 = 绿色       A = 淡绿色
	  3 = 湖蓝色     B = 淡浅绿色
	  4 = 红色       C = 淡红色
	  5 = 紫色       D = 淡紫色
	  6 = 黄色       E = 淡黄色
	  7 = 白色       F = 亮白色 
	此命令会改变DOS窗口中的全部文本和背景（不方便局部定制色彩）
 */
	
	printf("●"); 
	printf("●");
	printf("●");
	printf("●");
	
	return 0;
}

