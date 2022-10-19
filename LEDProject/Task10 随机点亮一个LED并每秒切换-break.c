/**
 * @file Task10 随机点亮一个LED并每秒切换-break.c
 * @brief: 演示知识点：多重循环+循环与选择的嵌套、随机数生成、break
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

	int random=0,preRandom=0; //定义变量preRandom保存上一个随机数
	//rand()函数会产生范围为0至32767的随机数
	
	while(1){
		system("cls");  //清屏
		
		//产生不同随机数：内层while(1)+break方式
		while(1){  
			random=rand()%8+1;
			if(random!=preRandom){ //如果新随机数与上一个数相同，需要重新产生随机数
				preRandom=random;  //更新随机数
				break;  //只有新随机数不同时，再显示
			}
		}
		
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
		sleep(1);	
	}
	
	
	return 0;
}

