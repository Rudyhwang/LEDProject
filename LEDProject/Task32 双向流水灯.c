/**
 * @file Task32 ˫����ˮ��.c
 * @brief: ��ʾ֪ʶ�㣺��ѭ���ڵ�״̬�ж�
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour); 
}
void hideCursor(){  //���ع�꣬���ٹ����Ӿ���Ӱ��
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main(){
	system("color F4\n");

	gotoxy(10,4);
	printf("˫����ˮ�ƣ�\n");
	hideCursor();

	int i=8,f=1;  //����ͷ��־f
	while(1){
		gotoxy(10,5);
		for(int j=0; j<i; j++){
			printf("��");
		}
		for(int j=i; j<8; j++){
			printf("��");
		}
		if(f==1){
			i++;
			if(i==9){
				i--;
				f=0;
			}
		}else{
			i--;
			if(i==-1){
				i++;
				f=1;
			}
		}
		sleep(1);
		gotoxy(10,5);
	}

	return 0;
}

