/**
 * @file Task02 ���LED���������ʾ.c 
 * @brief: ��ʾ֪ʶ�㣺��ʶ�����������������롢ѡ��ṹ������
 * @author: ���ȶ�
 * @date: 2022-10-18 21:09:13
 * 
 **/

#include<stdio.h>	//printf()	�������ڿ�
#include<conio.h> 	//getch()	�������ڿ�
#include<windows.h>	//system()��Sleep(xms)	�������ڿ�
#include<unistd.h>	//sleep()	�������ڿ�

int main(){
	char symbol;  //������������ڽ��ռ�������
	printf("�밴�س�����ʼ��\n");
	symbol=getch();  //���벻��ʾ
	if(symbol=='\r'){  //����Enter�س���
		system("cls"); //������Ȼ����ʾLED
	}else{
		printf("������Ĳ��ǻس�����\n���������г���");
		return 0;  //��exit(0);
	}
	//system()����ִ��DOS(windowsϵͳ)��shell(Linux/Unixϵͳ)����
	system("color F4\n");
/*  ��ɫ������ʮ����������ָ�������Ϊ����ɫ���ұ�Ϊǰ��ɫ
	  0 = ��ɫ       8 = ��ɫ
	  1 = ��ɫ       9 = ����ɫ
	  2 = ��ɫ       A = ����ɫ
	  3 = ����ɫ     B = ��ǳ��ɫ
	  4 = ��ɫ       C = ����ɫ
	  5 = ��ɫ       D = ����ɫ
	  6 = ��ɫ       E = ����ɫ
	  7 = ��ɫ       F = ����ɫ 
	�������ı�DOS�����е�ȫ���ı��ͱ�����������ֲ�����ɫ�ʣ�
 */
	
	printf("��"); sleep(1);  	//sleep()������λΪ��
	printf("��"); sleep(1);		//sleep()ͷ�ļ�Ϊunistd.h
	printf("��"); Sleep(1000);	//Sleep()������λΪ��
	printf("��"); Sleep(1000);	//Sleep()ͷ�ļ�Ϊwindows.h
	
	return 0;
}

