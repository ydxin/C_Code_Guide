#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p1, * p2;
	p1 = (int*)malloc(sizeof(int));//malloc������г�ʼ��
	p2 = (int*)calloc(5,sizeof(int)); //calloc���ʼ��Ϊ0
	printf("%d\n", *p1);
	printf("%d\n", *p2);
	return 0;
}