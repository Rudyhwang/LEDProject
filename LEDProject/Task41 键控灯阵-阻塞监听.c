/**
 * @file Task41 ���ص���.c
 * @brief: ��ʾ֪ʶ�㣺�����źš�����ʽ������һֱ�ȴ���
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
	char ch;
	//ѭ��������ֱ����Esc���˳�
	while(1){
		ch=getch();
		if(ch==27){  //ֱ����Esc���˳� 
			break;
		}
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

/*
  �˴���Ҫע��getchar��getch��getche��������������
>getchar��������C���Ա�׼���еĺ�������ͷ�ļ�stdio�У����Խ����û������һ���ַ����س�������������ʾ��
>getch������Ҳ�ǽ��ռ��������һ���ַ��������ûس�ȷ�ϣ�ʹ��ʱҪ����conio.h��ͷ�ļ���ע�⣬�û�����һ���ַ��ǲ���ʾ�ģ�
>getche������ͬ������һ���ַ���Ҳ��conio.hͷ�ļ���������Ҳ����Ҫ�س�ȷ�ϣ�������ʱ������ʾ�����ԣ�

 */
