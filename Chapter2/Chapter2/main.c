#include <stdio.h>
#include "Chapter2.h"

int main()
{
	float g1;
	float g2;
	float g3;
	float temp;
	float garray[3];
	scanf_s("%f %f %f", &g1, &g2, &g3);
	garray[0] = g1;
	garray[1] = g2;
	garray[2] = g3;
	BubbleSort(garray,3);
	printf("%f  %f  %f",garray[0], garray[1], garray[2]);
	return 0;
}