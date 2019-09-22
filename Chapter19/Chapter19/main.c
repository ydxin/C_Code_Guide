#include "chapter19.h"
#include <stdio.h>   
#include <string.h>   
#include <windows.h>   
#include <sql.h>   
#include <sqlext.h>   
#include <sqltypes.h>   
#include <odbcss.h>   

SQLHENV henv = SQL_NULL_HENV;
SQLHDBC hdbc1 = SQL_NULL_HDBC;
SQLHSTMT hstmt1 = SQL_NULL_HSTMT;
SQLRETURN ret;
int main()
{
	
	ConnectSQL(&henv, &hdbc1);
	//SQL���
	UCHAR	 sql[200] = "SELECT * FROM class";
	//��ѯ�Ľ�����ص���Щ������
	SQLCHAR �༶���[10], �༶����[15], ������[10], ����[10], ϵ��[10];
	SQLINTEGER no = SQL_NTS, nname = SQL_NTS, headmaster = SQL_NTS, num = SQL_NTS, pro = SQL_NTS;
	//����SQL���
	ret = InsertSQL(&hstmt1, &hdbc1, sql);
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
	{
		//�����ݻ����������ݿ��е���Ӧ�ֶΣ������ֱ��ʾ������С��������͡����ջ��塢���峤�ȡ����صĳ��ȣ�
		ret = SQLBindCol(hstmt1, 1, SQL_C_CHAR, �༶���, 10, &no);
		ret = SQLBindCol(hstmt1, 2, SQL_C_CHAR, �༶����, 15, &nname);
		ret = SQLBindCol(hstmt1, 3, SQL_C_CHAR, ������, 10, &headmaster);
		ret = SQLBindCol(hstmt1, 4, SQL_C_CHAR, ����, 10, &num);
		ret = SQLBindCol(hstmt1, 5, SQL_C_CHAR, ϵ��, 10, &pro);
	}
	//��������
	while ((ret = SQLFetch(hstmt1)) != SQL_NO_DATA_FOUND)
	{
		if (ret == SQL_ERROR)
			printf("���ݲ�ѯ����\n");
		else if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
		{
			printf("�༶���Ϊ%s�İ�������%s���༶����%s�ˣ���%s\n", �༶���, ������, ����, ϵ��);
		}
		else
		{
			printf("���ݲ�ѯ����!\n");
			break;
		}
	}
	
	//�ͷ�����
	DisconnectSQL(&henv, &hdbc1,&hstmt1);
	return 0;
}