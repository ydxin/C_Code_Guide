#include "Chapter7.h"
#include <stdio.h>
#include <string.h>
 static void printTest()
{
	printf("in Chapter7.c");
}

 void JugeYMD()
 {
	 int year = 0;
	 int mon = 0;
	 int day = 0;
	 int ymd = 0;
	 int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	 int daysAll = 0;
	 printf("��������ݣ�  ");
	 scanf_s("%d",&ymd);
	 year = ymd / 10000;
	 day = ymd % 100;
	 mon = ymd % 10000 / 100;
	 printf("%d��%d��%d��\n",year,mon,day);
	 for (int i = 0; i < mon; i++)
	 {
		 daysAll = daysAll + days[i];
	 }
	 daysAll = daysAll + day;
	 printf("����%d��ĵ�%d��", year, daysAll);

 }

 void JugeArray()
 {
	 char a1[] = "192.168.1.1";
	 char a2[] = "192.66.72";
	 char a3[] = "10.199.88.132";
	 char a4[] = "192.168.1.1";
	 char a5[] = "192.168.163";
	 char* a[5] = { a1,a2,a3,a4,a5 };
	 for (int i = 0; i < 5; i++)
	 {
		 for (int j = i+1; j < 5; j++)
		 {
			 if (!strcmp(a[i], a[j]))
			 {
				 printf("%s�ظ���", a[j]);
			 }
		 }
	 }


 }

 void ChangeUp()
 {
	 char a[1000];
	 printf("��������ĸ��  \n");
	 scanf("%s", a);
	 printf("%s", strupr(a));
 }

 void HuiWen()
 {
	 char a[1000];
	 int len = 0;
	 printf("�������ַ�����  \n");
	 scanf("%s", a);
	 len = strlen(a);
	 for (int i = 0; i < len; i++)
	 {
		 if (len - i - 1 >= i)
		 {
			 if (!(a[i]==a[len-i-1]))
			 {
				 printf("%s���ǻ�����", a);
				 return;
			 }
		 }
	 }
	 printf("%s�ǻ�����", a);

 }