/**
 * @file Task08 ������ˮ��.c
 * @brief: ��ʾ֪ʶ�㣺˫��ѭ����ѭ��Ƕ�ס�������ѭ��
 * @author: ���ȶ�
 * @date: 2022-10-18 21:09:13
 * 
 **/

#include<stdio.h>	//printf()	�������ڿ�
#include<conio.h> 	//getch()	�������ڿ�
#include<windows.h>	//system()��Sleep(xms)	�������ڿ�
#include<unistd.h>	//sleep()	�������ڿ�

#define NUM 8
int main(){
	system("color F4\n");

	while(1){ //������ѭ��
		system("cls");
		for(int i=0;i<NUM;i++){  //C99��׼��Ҫ��i������{��ʼ��
			printf("��"); sleep(1);
		}
	}
	
	return 0;
}

