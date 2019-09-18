#include <stdio.h>
#include "Chapter9.h"

int main()
{
	Student stu[5];
	stu[3].a = 1;
	printf("%d", (stu+3)->a);
 }  