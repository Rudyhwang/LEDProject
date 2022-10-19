/**
 * @file Task42 键控灯阵.c
 * @brief: 演示知识点：异步输入信号、异步中断、非阻塞式监听（不用等待）、kbhit()函数
 * @author: 黄先栋
 * @date: 2022-10-18 21:09:13
 * 到特定位置可以检测数据，没有输入也不影响程序执行，可用于模拟非实时性中断或传感器信号异步输入
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
		if(kbhit())  //缓冲区是否有数据，有则返回非0值，读取；没有返回0，不影响后面程序
		{
			ch=getch();
			if(ch==13 || ch==32){ //若为回车或空格
				getch();  //等待再按一键。相当于暂停，再按任意键继续。
			}else if(ch==27)  //若是Esc键则退出
			{
				break;
			}
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

