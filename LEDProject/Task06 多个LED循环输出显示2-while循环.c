/**
 * @file Task06 ���LEDѭ�������ʾ2-whileѭ��.c 
 * @brief: ��ʾ֪ʶ�㣺whileѭ��
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
	int i=0;
	while(i<NUM){  //C99��׼��Ҫ��i������{��ʼ��
		printf("��"); sleep(1);
		i++;
	}
	
	return 0;
}

