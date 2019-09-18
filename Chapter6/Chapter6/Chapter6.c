#include "Chapter6.h"
#include <stdio.h>
#include <string.h>
void InputNums()
{
	int array[INPUT_NUM] = { 0 };
	printf("请输入%d个数： \n", INPUT_NUM);
	for (int i = 0; i < INPUT_NUM; i++)
	{
		scanf("%d", &array[i]);
	}
}

void SelectMaxSort(int* p, int len)
{
	int temp = 0;
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		temp = *(p + i);
		index = i;
		for (int j = i+1; j < len; j++)
		{
			if (temp < *(p + j))
			{
				temp = *(p + j);
				index = j;
			}
		}
		*(p +index) = *(p + i);
		*(p + i) = temp;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", *(p + i));
	}
	
}

void ExchangeSort(int* p, int len)
{
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (p[i] < p[j])
			{
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", *(p + i));
	}
	
}

void BubbleSort(int* p, int len)
{
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j =1; j < len-i; j++)
		{
			if (p[j-1] < p[j])
			{
				temp = p[j];
				p[j] = p[j-1];
				p[j-1] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", *(p + i));
	}
}

void InsertSort(int* p, int len)
{
	for (int i = 1; i < len;i++)
	{
		int pos = i - 1;
		int temp = p[i];
		while (pos>=0 && temp>p[pos])
		{
			p[pos + 1] = p[pos];
			pos--;
		}
		p[pos+1] = temp;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", *(p + i));
	}
}

void BinaryCore(int* p, int left ,int right,int len)
{
	int iLeft = left;
	int jRight = right;
	int middle =p[ (left + right) / 2 ];
	int temp = 0;
	do
	{
		while (p[iLeft]>middle && iLeft < right)
			iLeft++;
		while (p[jRight] <middle&& jRight > left)
			jRight--;
		if (iLeft <= jRight)
		{
			temp = p[iLeft];
			p[iLeft] = p[jRight];
			p[jRight]= temp ;
			iLeft++;
			jRight--;
		}
	} while (iLeft<= jRight);
	if (left < jRight)
	{
		BinaryCore(p, left+1, jRight, jRight - left );
	}
	if (right > iLeft)
	{
		BinaryCore(p, iLeft, right-1, right - iLeft );
	}
}

void BinarySort(int* p, int len)
{
	BinaryCore(p, 0, len - 1, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", *(p + i));
	}
}

void QianNianChong()
{
	int people[PEOPLE_NUM] = { 0 };
	printf("请输入%d个人的序列信息:   ", PEOPLE_NUM);
	for (int i = 0; i < PEOPLE_NUM; i++)
	{
		scanf("%d", &people[i]);
		if (people[i] < 99 && people[i] >= 20)
		{
			people[i] = people[i] + 1900;
		}
		else if (people[i] == 0)
		{
			people[i] = people[i] + 2000;
		}
	}
	BubbleSort(people, PEOPLE_NUM);
}

void SuShu()
{
	int not_su_flag = 1;

	for (int i = 2; i <= 50; i++)
	{
		not_su_flag = 0;
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				not_su_flag = 1;
				break;
			}
		}
		if (not_su_flag == 0)
		{
			printf("%d  ", i);
		}
	}
}

void FeiBoNaQi()
{
	unsigned long  a1 = 1;
	unsigned long  a2 = 1;
	unsigned long  a3 = 2;
	unsigned long  a[40] = { 1,1,2 };
	for (int i = 3; i < 40; i++)
	{
		a1 = a2;
		a2 = a3;
		a3 = a1 + a2;
		a[i] = a3;
	}
	for (int i = 0; i < 40; i++)
	{
		printf("%d ", a[i]);
	}
}