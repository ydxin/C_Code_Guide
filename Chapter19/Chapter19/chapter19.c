#include "chapter19.h"
#include <odbcss.h>
#include <stdio.h>
void ConnectSQL(SQLHENV* henv, SQLHDBC* hdbc)
{
	RETCODE retcode;
	//���������˺š�����
	UCHAR servername[SQL_MAX_DSN_LENGTH + 1] = "usersql";
	UCHAR id[MAXNAME] = "sa";
	UCHAR auth[MAXNAME] = "ydx";
	SQLSMALLINT serlen = strlen(servername);
	SQLSMALLINT idlen = strlen(id);
	SQLSMALLINT authlen = strlen(auth);
	//1.��������Դ�����û������
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, henv);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
		retcode = SQLSetEnvAttr(*henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);  //���û�������
	else
	{
		printf("���뻷�����ʧ��!\n");
		return 0;
	}
	//2.���Ӿ�� 
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
		retcode = SQLAllocHandle(SQL_HANDLE_DBC, *henv, hdbc);  //�������Ӿ��
	else 
	{
		printf("���û�������ʧ��!\n");
		return 0;
	}
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
#ifdef SQLDRIVERCONNECT
		SQLDriverConnectW(*hdbc, NULL, L"DRIVER={SQL Server};SERVER=YDX-LAB;DATABASE=mrkj;UID=sa;PWD=ydx;", SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
#else
	retcode = SQLConnect(*hdbc, servername, serlen, id, idlen, auth, authlen);
#endif
	else
	{
		printf("�������Ӿ��ʧ��!\n");
		return 0;
	}
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
		printf("���ӳɹ�!\n");
	else
	{
		printf("�������ݿ�ʧ��!\n");
		return 0;
	}

}


void DisconnectSQL(SQLHENV* henv, SQLHDBC* hdbc, SQLHSTMT* hstmt)
{
	//3.�Ͽ�����Դ
	/*
	1.�Ͽ�������Դ������.
	2.�ͷ����Ӿ��.
	3.�ͷŻ������(���������Ҫ���������������������)
	*/
	SQLDisconnect(*hdbc);
	SQLCloseCursor(*hstmt);
	SQLFreeHandle(SQL_HANDLE_DBC, *hdbc);
	SQLFreeHandle(SQL_HANDLE_ENV, *henv);
	SQLFreeHandle(SQL_HANDLE_STMT, *hstmt);
	printf("����Դ�Ͽ��ɹ���\n");
}

SQLRETURN InsertSQL(SQLHSTMT* hstmt, SQLHDBC* hdbc, UCHAR* sqlarr)
{
	RETCODE retcode;
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, *hdbc, hstmt);
#ifdef SET_STMT_ATTR
	retcode = SQLSetStmtAttr(*hstmt, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, SQL_IS_INTEGER);
#endif // SET_STMT_ATTR

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode=SQLExecDirect(*hstmt, sqlarr, SQL_NTS);
		printf("�����ɹ�!\n");
	
	}
	else 
	{
		printf("�����������ľ��ʧ�ܣ��޷�����SQLִ��!\n");
	}
	return retcode;
}


;
;
;