#include "Chapter2.h"
void BubbleSort(float* p, int len)
{
	int temp=0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (p[i] < p[j])
			{
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}
}