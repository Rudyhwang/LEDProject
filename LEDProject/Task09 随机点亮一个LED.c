/**
 * @file Task09 �������һ��LED.c
 * @brief: ��ʾ֪ʶ�㣺ѭ����ѡ���Ƕ�ס����������
 * @author: ���ȶ�
 * @date: 2022-10-18 21:09:13
 * 
 **/

#include<stdio.h>	//printf()	�������ڿ�
#include<conio.h> 	//getch()	�������ڿ�
#include<windows.h>	//system()��Sleep(xms)	�������ڿ�
#include<unistd.h>	//sleep()	�������ڿ�
#include<time.h> 	//time()	�������ڿ�
#include<stdlib.h>  //srand()��rand() �������ڿ�

#define NUM 8
int main(){
	system("color F4\n");
	//srand��rand()���ʹ�ò���α��������С�
	//srand()��������������ĳ�ʼ��������
	srand(time(0));  //��ʱ����ΪNULL����궨��ֵ��0

	int random;
	//rand()�����������ΧΪ0��32767�������
	random=rand()%8+1;  //��LED���Ϊ1~8ʱ����1
	printf("���������Ϊ��%d\n",random);
	for(int i=1;i<=8;i++){  //��LED���Ϊ1~8ʱ
		//printf("%d",i); //��ѡ�Ƿ���ʾ���
		if(i==random)
		{
			printf("��");
		}
		else
		{
			printf("��");
		}
	}
	
	return 0;
}

