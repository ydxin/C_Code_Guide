#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p1, * p2;
	p1 = (int*)malloc(sizeof(int));//malloc不会进行初始化
	p2 = (int*)calloc(5,sizeof(int)); //calloc会初始化为0
	printf("%d\n", *p1);
	printf("%d\n", *p2);
	return 0;
}