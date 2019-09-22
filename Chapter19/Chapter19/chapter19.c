#include "chapter19.h"
#include <odbcss.h>
#include <stdio.h>
void ConnectSQL(SQLHENV* henv, SQLHDBC* hdbc)
{
	RETCODE retcode;
	//服务器、账号、密码
	UCHAR servername[SQL_MAX_DSN_LENGTH + 1] = "usersql";
	UCHAR id[MAXNAME] = "sa";
	UCHAR auth[MAXNAME] = "ydx";
	SQLSMALLINT serlen = strlen(servername);
	SQLSMALLINT idlen = strlen(id);
	SQLSMALLINT authlen = strlen(auth);
	//1.连接数据源，设置环境句柄
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, henv);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
		retcode = SQLSetEnvAttr(*henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);  //设置环境属性
	else
	{
		printf("申请环境句柄失败!\n");
		return 0;
	}
	//2.连接句柄 
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
		retcode = SQLAllocHandle(SQL_HANDLE_DBC, *henv, hdbc);  //分配连接句柄
	else 
	{
		printf("设置环境属性失败!\n");
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
		printf("分配连接句柄失败!\n");
		return 0;
	}
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
		printf("连接成功!\n");
	else
	{
		printf("连接数据库失败!\n");
		return 0;
	}

}


void DisconnectSQL(SQLHENV* henv, SQLHDBC* hdbc, SQLHSTMT* hstmt)
{
	//3.断开数据源
	/*
	1.断开与数据源的连接.
	2.释放连接句柄.
	3.释放环境句柄(如果不再需要在这个环境中作更多连接)
	*/
	SQLDisconnect(*hdbc);
	SQLCloseCursor(*hstmt);
	SQLFreeHandle(SQL_HANDLE_DBC, *hdbc);
	SQLFreeHandle(SQL_HANDLE_ENV, *henv);
	SQLFreeHandle(SQL_HANDLE_STMT, *hstmt);
	printf("数据源断开成功！\n");
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
		printf("操作成功!\n");
	
	}
	else 
	{
		printf("分配申请语句的句柄失败，无法进行SQL执行!\n");
	}
	return retcode;
}


;
;
;