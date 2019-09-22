#include <stdio.h>
/*
FILE *fp;
fp=fopen("a.txt",w+);
fclose(fp);
fputc(char,fp);
fgetc(fp);
fputs("abc",fp);
fgets(字符数组,n,fp); 读取n个字符
fprintf(fp,"%d",i);
fscanf(fp,"%d",&i);
fread(buffter,size,count,fp); 从文件中读取count次，每次读size个字节，读取的内容存放在buffter地址中
fwrite(buffter,size,count,fp); 从buffter地址中将数据输出count次，每次size个字节
fseek(fp,-20,1);  fseek(文件指针，位移量，起始点)
rewind(fp);
ftell(fp);得到相对于文件开头的位移量；
*/
int main()
{
	FILE* fp;
	fp = fopen("test.txt","r+");
	fputs("Together we create a team culture ", fp);
	return 0;
}