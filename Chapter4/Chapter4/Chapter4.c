#include "Chapter4.h"
#include <stdio.h>
#include <math.h>
void BuyChickens()
{
	int i, j, k;
	for (i = 0; i <= 100; i++)
	{
		for (j = 0; j <= 100; j++)
		{
			for (k = 0; k <= 100; k++)
			{
				if (i + j + k == 100 && 5 * i + 3 * j + k * 1 / 3 == 100)
					printf("公鸡有%d只，母鸡有%d只，小鸡有%d只\n", i, j, k);
			}
		}
	}
}

void ShuiXianShu()
{
	int bai=0;
	int shi=0;
	int ge=0;
	int num=0;
	for (bai = 0; bai < 10; bai++)
	{
		for (shi = 0; shi < 10; shi++)
		{
			for (ge = 0; ge < 10; ge++)
			{
				num = bai * 100 + shi * 10 + ge * 1;
				if (num==(pow(bai,3)+ pow(shi, 3) + pow(ge, 3)))
				{
					printf("%d%d%d\n", bai, shi, ge);
				}
			}
		}
	}
}

void TaxiPrice()
{
	float kilos = 0;
	float price = 0;
	printf("请输入公里数：  \n");
	scanf_s("%f",&kilos);
	price=(kilos > 2.5)* ((kilos - 2.5) * 1.3 +1)+ 5;
	printf("收费总价为： %f",price);

}