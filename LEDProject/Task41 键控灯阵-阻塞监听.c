/**
 * @file Task41 键控灯阵.c
 * @brief: 演示知识点：数字信号、阻塞式监听（一直等待）
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
	colour+=0xF0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour); 
}
void hideCursor(){  //隐藏光标，减少光标对视觉的影响
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main(){
	system("color F4\n");
	hideCursor();
	int random=0,preRandom=0;
	char ch;
	//循环监听，直到按Esc键退出
	while(1){
		ch=getch();
		if(ch==27){  //直到按Esc键退出 
			break;
		}
		gotoxy(20,5);  //可以任意位置输出
		
		//生成随机数(前景色)
		random=rand()%16;
		//如果新随机数与上一个数相同，则重新产生随机数
		if(random==preRandom){ 
			continue;
		}
		color(random);
		
		//输出显示LED正方形矩阵
		for(int i=0;i<8;i++){
			gotoxy(20,5+i); 
			for(int j=0;j<8;j++){
				printf("●");
			}
			printf("\n");
		}
		sleep(1); //每秒变换一次颜色
	}
	
	return 0;
}

/*
  此处需要注意getchar、getch、getche三个函数的区别：
>getchar函数，是C语言标准库中的函数，在头文件stdio中，可以接受用户输入的一个字符，回车结束，明文显示。
>getch函数，也是接收键盘输入的一个字符，但不用回车确认！使用时要包含conio.h的头文件。注意，用户输入一个字符是不显示的！
>getche函数，同样接收一个字符，也在conio.h头文件中声明，也不需要回车确认！但输入时明文显示（回显）

 */
