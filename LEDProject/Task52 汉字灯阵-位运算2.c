/**
 * @file Task34 键控灯阵.c
 * @brief: 演示知识点：异步输入信号、异步中断、非阻塞式监听（不用等待）、kbhit()函数
 * @author: 黄先栋
 * @date: 2022-10-19 13:09:13
 * 到特定位置可以检测数据，没有输入也不影响程序执行，可用于模拟非实时性中断或传感器信号异步输入
 **/

#include<stdio.h>	//printf()	函数所在库
#include<conio.h> 	//getch()	函数所在库
#include<windows.h>	//system()、Sleep(xms)	函数所在库
#include<unistd.h>	//sleep()	函数所在库

static const unsigned char bitmap1[] = {//汉
	0x00, 0x00, 
	0x27, 0xf8, 
	0x12, 0x08, 
	0x12, 0x08, 
	0x82, 0x08, 
	0x41, 0x10, 
	0x49, 0x10, 
	0x09, 0x10, 
	0x10, 0xa0, 
	0x10, 0xa0, 
	0xe0, 0x40, 
	0x20, 0x40, 
	0x20, 0xa0, 
	0x21, 0x10, 
	0x22, 0x08, 
	0x0c, 0x06
};
static const unsigned char bitmap2[] = {//字
	0x02, 0x00, 
	0x01, 0x00, 
	0x7f, 0xfe, 
	0x40, 0x02, 
	0x80, 0x04, 
	0x1f, 0xe0, 
	0x00, 0x40, 
	0x00, 0x80, 
	0x01, 0x00, 
	0xff, 0xfe, 
	0x01, 0x00, 
	0x01, 0x00, 
	0x01, 0x00, 
	0x01, 0x00, 
	0x05, 0x00, 
	0x02, 0x00
};

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
	unsigned char choose=0x80;
	//循环监听，直到按Esc键退出
	while(1){
		//输出显示LED矩阵16*16汉
		system("cls");
		for(int i=0;i<32;i++){
			choose=0x80;
			for(int j=0;j<8;j++){
				if(bitmap1[i]&choose){
					printf("●");
				}else{
					printf("○");
				}
				choose>>=1;
			}
			if(i%2){
				printf("\n");
			}
		}
		sleep(1); //每秒变换一次颜色
		
		//输出显示LED矩阵16*16字
		system("cls");
		for(int i=0;i<32;i++){
			choose=0x80;
			for(int j=0;j<8;j++){
				if(bitmap2[i]&choose){
					printf("●");
				}else{
					printf("○");
				}
				choose>>=1;
			}
			if(i%2){
				printf("\n");
			}
		}
		sleep(1); //每秒变换一次颜色
	}
	
	return 0;
}

