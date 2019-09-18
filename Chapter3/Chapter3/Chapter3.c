#include "Chapter3.h"
#include <stdio.h>
#define PI 3.1415926
float CalcCirSize(float C, float height)
{
	float radius = 0;
	float Vsize = 0;
	radius = C / 2 / PI;
	Vsize = radius * radius * PI * height;
	printf("V is %f\n", Vsize);
	return Vsize;
}

void CalcAscii(char c)
{
	printf("%d",c);
}