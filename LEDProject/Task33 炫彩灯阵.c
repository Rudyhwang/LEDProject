/**
 * @file Task33 �Ųʵ���.c
 * @brief: ��ʾ֪ʶ�㣺˫��ѭ����ѭ��Ƕ�ס�������ѭ��
 * @author: ���ȶ�
 * @date: 2022-10-18 21:09:13
 * 
 **/

#include<stdio.h>	//printf()	�������ڿ�
#include<conio.h> 	//getch()	�������ڿ�
#include<windows.h>	//system()��Sleep(xms)	�������ڿ�
#include<unistd.h>	//sleep()	�������ڿ�

//���Ŷ�λ����������ռ2���ַ���ȣ�
void gotoxy(short y, short x)  //�С��С����Ͻ�Ϊ(0,0)
{
	COORD coord = {y, x};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void color(int colour){  //Ϊ����д���㡢������ȷ
	colour+=0xF0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour); 
}
void hideCursor(){  //���ع�꣬���ٹ����Ӿ���Ӱ��
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main(){
	system("color F4\n");
	hideCursor();
	int random=0,preRandom=0;
	
	while(1){
		gotoxy(20,5);  //��������λ�����
		
		//���������(ǰ��ɫ)
		random=rand()%16;
		//��������������һ������ͬ�������²��������
		if(random==preRandom){ 
			continue;
		}
		color(random);
		
		//�����ʾLED�����ξ���
		for(int i=0;i<8;i++){
			gotoxy(20,5+i); 
			for(int j=0;j<8;j++){
				printf("��");
			}
			printf("\n");
		}
		sleep(1); //ÿ��任һ����ɫ
	}
	
	return 0;
}

