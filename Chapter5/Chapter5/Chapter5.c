#include "Chapter5.h"
#include <stdio.h>
void ShowPeach()
{
	int i = 1;
	int num =((((i * 5 + 1) * 5 + 1) * 5 + 1) * 5 + 1) * 5 + 1;
	printf("Peach num is %d\n",num);
}

void  SolveMath()
{
	int a = 0;
	printf("请输入a的值： \n");
	scanf_s("%d",&a);
	int b = 0;
	if (a < 50)
	{
		b = 3 * a;
	}
	else if (a < 500)
	{
		b = 6 * a + 60;
	}
	else
	{
		b = 9 * a - 90;
	}
	printf("%d\n",b);
}

void ShowMonths()
{
	for (int i = 1; i < 13; i++)
	{
		switch (i)
		{
		case 1:
			printf("31\n");
			break;
		case 2:
			printf("28\n");
			break;
		case 3:
			printf("31\n");
			break;
		case 4:
			printf("30\n");
			break;
		case 5:
			printf("31\n");
			break;
		case 6:
			printf("30\n");
			break;
		case 7:
			printf("31\n");
			break;
		case 8:
			printf("31\n");
			break;
		case 9:
			printf("30\n");
			break;
		case 10:
			printf("31\n");
			break;
		case 11:
			printf("30\n");
			break;
		case 12:
			printf("31\n");
			break;
		default:
			break;
		}
	}
}

void MonthsJuge()
{
	int month = 0;
	printf("请输入年份： \n");
	scanf_s("%d",&month);
	if (month % 400 == 0 || (month % 4 == 0 && month % 100 != 0))
	{
		printf("%d 是闰年： \n", month);
	}
	else
	{
		printf("%d 不是闰年： \n", month);
	}
}

void CalcMeters()
{
	float result = 50;
	float sum = 50;
	for (int i = 0; i < 5; i++)
	{
		result = result * 1 / 3;
		sum = 2*result + sum;
	}
	sum = sum - result;
	printf("共%f米", sum);
}