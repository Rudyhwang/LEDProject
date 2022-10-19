/**
 * @file Task34 ���ص���.c
 * @brief: ��ʾ֪ʶ�㣺�첽�����źš��첽�жϡ�������ʽ���������õȴ�����kbhit()����
 * @author: ���ȶ�
 * @date: 2022-10-19 13:09:13
 * ���ض�λ�ÿ��Լ�����ݣ�û������Ҳ��Ӱ�����ִ�У�������ģ���ʵʱ���жϻ򴫸����ź��첽����
 **/

#include<stdio.h>	//printf()	�������ڿ�
#include<conio.h> 	//getch()	�������ڿ�
#include<windows.h>	//system()��Sleep(xms)	�������ڿ�
#include<unistd.h>	//sleep()	�������ڿ�

static const unsigned char bitmap1[] = {//��
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
static const unsigned char bitmap2[] = {//��
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
	unsigned char choose=0x80;
	//ѭ��������ֱ����Esc���˳�
	while(1){
		//�����ʾLED����16*16��
		system("cls");
		for(int i=0;i<32;i++){
			choose=0x80;
			for(int j=0;j<8;j++){
				if(bitmap1[i]&choose){
					printf("��");
				}else{
					printf("��");
				}
				choose>>=1;
			}
			if(i%2){
				printf("\n");
			}
		}
		sleep(1); //ÿ��任һ����ɫ
		
		//�����ʾLED����16*16��
		system("cls");
		for(int i=0;i<32;i++){
			choose=0x80;
			for(int j=0;j<8;j++){
				if(bitmap2[i]&choose){
					printf("��");
				}else{
					printf("��");
				}
				choose>>=1;
			}
			if(i%2){
				printf("\n");
			}
		}
		sleep(1); //ÿ��任һ����ɫ
	}
	
	return 0;
}

