#include "Chapter9.h"
#include <stdio.h>
void PrintUnionSize()
{
	unsigned int len = sizeof(UserUnion);
	printf("%d",len);
}