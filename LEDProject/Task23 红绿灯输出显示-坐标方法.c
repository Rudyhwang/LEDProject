/**
 * @file Task223 ���̵������ʾ-���귽��.c
 * @brief: ��ʾ֪ʶ�㣺gotoxy(x,y)����
 * @author: ���ȶ�
 * @date: 2022-10-18 22:19:13
 * 
 **/

#include<stdio.h>	//printf()	�������ڿ�
#include<conio.h> 	//getch()	�������ڿ�
#include<windows.h>	//system()	�������ڿ�
#include<unistd.h>	//sleep()	�������ڿ�

//�궨��ǰ��ɫ
#define RED 12
#define YLW 14
#define GRN 2

//COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ
/*��ԭ��Ϊ��
  typedef struct _COORD {
  SHORT X; // ������
  SHORT Y; // ������
  } COORD; */

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
void init(){  		//��ʼ��
	hideCursor();
	color(2);		//��ɫ��0x2
	printf("��"); 
	color(14);		//��ɫ��0xE
	printf("��"); 
	color(12);		//��ɫ��0xC
	printf("��"); 
}
void red(){
	system("cls");
//	printf("\r");	//�س����ص����ף����������Ḳ�Ǳ���ԭ������
	gotoxy(4,0);
//	color(GRN);printf("��");	
//	color(YLW);printf("��");
	color(RED);printf("��");
}
void ylwFill(){
	system("cls");
//	printf("\r");
	gotoxy(2,0);
//	color(GRN);printf("��");	
	color(YLW);printf("��");
//	color(RED);printf("��");
}
void ylwEmpty(){
//	system("cls");
//	printf("\r");
	gotoxy(2,0);
//	color(GRN);printf("��");	
	color(YLW);printf("��");
//	color(RED);printf("��");
}
void grn(){
	system("cls");
	gotoxy(0,0);
	color(GRN);printf("��");	
//	color(YLW);printf("��");
//	color(RED);printf("��");
}

int main(){
	//system()����ִ��DOS(windowsϵͳ)��shell(Linux/Unixϵͳ)����
	system("color 0F\n");//��ɫ����
	/*  ��ɫ������ʮ����������ָ�������Ϊ����ɫ���ұ�Ϊǰ��ɫ
	  0 = ��ɫ       8 = ��ɫ
	  1 = ��ɫ       9 = ����ɫ
	  2 = ��ɫ       A = ����ɫ
	  3 = ����ɫ     B = ��ǳ��ɫ
	  4 = ��ɫ       C = ����ɫ
	  5 = ��ɫ       D = ����ɫ
	  6 = ��ɫ       E = ����ɫ
	  7 = ��ɫ       F = ����ɫ 
	 */
	//�ֲ���ɫ���ã�ǰ��ɫ�뱳��ɫ��DOS��ͬ����ռ4bit���ɵ�������ǰ��ɫ��
	init();	sleep(2); //�ϵ��ʼ��2��
	while(1){
		grn();sleep(8);	//�̵�8��
		for(int i=0;i<3;i++){//�Ƶ���3��
			ylwFill();Sleep(500);
			ylwEmpty();Sleep(500);
		}		
		red();sleep(5);	//���5��
	}	
	return 0;
}

