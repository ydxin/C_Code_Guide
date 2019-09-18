#ifndef _CHAPTER9_H_
#define _CHAPTER9_H_

typedef union UserUnion
{
	int a;
	char c;
	double b;
}UserUnion;

typedef enum Fruits
{
	WATER,
	MANGO,
	APPLE
}Fruits;
void PrintUnionSize();

#endif
