/**
 * @file Task11 �������һ��LED��ÿ���л�-continue.c
 * @brief: ��ʾ֪ʶ�㣺����ѭ��+ѭ����ѡ���Ƕ�ס���������ɡ�continue
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

	int random=0,preRandom=0; //�������preRandom������һ�������
	//rand()�����������ΧΪ0��32767�������
	
	while(1){
		system("cls");  //����
		
		//������ͬ�������continue+���while(1)��ʽ
		random=rand()%8+1;
		if(random==preRandom){ //��������������һ������ͬ����Ҫ���²��������
			continue;
		}
		preRandom=random; 
		
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
		sleep(1);	
	}
	
	
	return 0;
}

