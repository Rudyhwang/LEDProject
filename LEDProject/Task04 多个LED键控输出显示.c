/**
 * @file Task02 多个LED键控输出显示.c 
 * @brief: 演示知识点：标识符、变量、键盘输入、选择结构、清屏
 * @author: 黄先栋
 * @date: 2022-10-18 21:09:13
 * 
 **/

#include<stdio.h>	//printf()	函数所在库
#include<conio.h> 	//getch()	函数所在库
#include<windows.h>	//system()、Sleep(xms)	函数所在库
#include<unistd.h>	//sleep()	函数所在库

int main(){
	char symbol;  //定义变量，用于接收键盘数据
	printf("请按回车键开始：\n");
	symbol=getch();  //输入不显示
	if(symbol=='\r'){  //按下Enter回车键
		system("cls"); //清屏，然后显示LED
	}else{
		printf("你输入的不是回车键！\n请重新运行程序！");
		return 0;  //或exit(0);
	}
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
	
	printf("●"); sleep(1);  	//sleep()参数单位为秒
	printf("●"); sleep(1);		//sleep()头文件为unistd.h
	printf("●"); Sleep(1000);	//Sleep()参数单位为秒
	printf("●"); Sleep(1000);	//Sleep()头文件为windows.h
	
	return 0;
}

