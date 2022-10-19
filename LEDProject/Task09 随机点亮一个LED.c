/**
 * @file Task09 随机点亮一个LED.c
 * @brief: 演示知识点：循环与选择的嵌套、随机数生成
 * @author: 黄先栋
 * @date: 2022-10-18 21:09:13
 * 
 **/

#include<stdio.h>	//printf()	函数所在库
#include<conio.h> 	//getch()	函数所在库
#include<windows.h>	//system()、Sleep(xms)	函数所在库
#include<unistd.h>	//sleep()	函数所在库
#include<time.h> 	//time()	函数所在库
#include<stdlib.h>  //srand()、rand() 函数所在库

#define NUM 8
int main(){
	system("color F4\n");
	//srand和rand()配合使用产生伪随机数序列。
	//srand()是随机数发生器的初始化函数。
	srand(time(0));  //有时参数为NULL，其宏定义值即0

	int random;
	//rand()函数会产生范围为0至32767的随机数
	random=rand()%8+1;  //当LED编号为1~8时：加1
	printf("本次随机数为：%d\n",random);
	for(int i=1;i<=8;i++){  //当LED编号为1~8时
		//printf("%d",i); //可选是否显示编号
		if(i==random)
		{
			printf("●");
		}
		else
		{
			printf("○");
		}
	}
	
	return 0;
}

