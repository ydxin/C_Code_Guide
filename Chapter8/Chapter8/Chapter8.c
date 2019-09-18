#include "Chapter8.h"
void ChaoZuoYe()
{
	int* p;
	int a = 10;
	p = &a;
	printf("%d", *p);
}

void DanCiNums()
{
	char a[100] = "I have a dream";
	char* p = a;
	int nums = 0;
	while (*p != '\0')
	{
		p++;
		if (*p == ' ')
		{
			
			continue;
		}
		nums++;
	}
	printf("%d", nums);
}

