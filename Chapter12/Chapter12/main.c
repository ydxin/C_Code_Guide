#include <stdio.h>
/*
FILE *fp;
fp=fopen("a.txt",w+);
fclose(fp);
fputc(char,fp);
fgetc(fp);
fputs("abc",fp);
fgets(�ַ�����,n,fp); ��ȡn���ַ�
fprintf(fp,"%d",i);
fscanf(fp,"%d",&i);
fread(buffter,size,count,fp); ���ļ��ж�ȡcount�Σ�ÿ�ζ�size���ֽڣ���ȡ�����ݴ����buffter��ַ��
fwrite(buffter,size,count,fp); ��buffter��ַ�н��������count�Σ�ÿ��size���ֽ�
fseek(fp,-20,1);  fseek(�ļ�ָ�룬λ��������ʼ��)
rewind(fp);
ftell(fp);�õ�������ļ���ͷ��λ������
*/
int main()
{
	FILE* fp;
	fp = fopen("test.txt","r+");
	fputs("Together we create a team culture ", fp);
	return 0;
}