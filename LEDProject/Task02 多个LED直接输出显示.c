/**
 * @file Task02 ���LEDֱ�������ʾ.c 
 * @brief: ��ʾ֪ʶ�㣺˳��ṹ
 * @author: ���ȶ�
 * @date: 2022-10-18 21:09:13
 * 
 **/

#include<stdio.h>	//printf()	�������ڿ�
#include<conio.h> 	//getch()	�������ڿ�
#include<windows.h>	//system()	�������ڿ�
#include<unistd.h>	//sleep()	�������ڿ�

int main(){
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
	
	printf("��"); 
	printf("��");
	printf("��");
	printf("��");
	
	return 0;
}

