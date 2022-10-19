/**
 * @file Task08 单向流水灯.c
 * @brief: 演示知识点：双重循环、循环嵌套、“死”循环
 * @author: 黄先栋
 * @date: 2022-10-18 21:09:13
 * 
 **/

#include<stdio.h>	//printf()	函数所在库
#include<conio.h> 	//getch()	函数所在库
#include<windows.h>	//system()、Sleep(xms)	函数所在库
#include<unistd.h>	//sleep()	函数所在库

#define NUM 8
int main(){
	system("color F4\n");

	while(1){ //“死”循环
		system("cls");
		for(int i=0;i<NUM;i++){  //C99标准会要求将i定义在{开始处
			printf("●"); sleep(1);
		}
	}
	
	return 0;
}

