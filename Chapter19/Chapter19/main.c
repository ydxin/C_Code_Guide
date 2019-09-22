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
	//SQL语句
	UCHAR	 sql[200] = "SELECT * FROM class";
	//查询的结果返回到这些变量里
	SQLCHAR 班级编号[10], 班级名称[15], 班主任[10], 人数[10], 系别[10];
	SQLINTEGER no = SQL_NTS, nname = SQL_NTS, headmaster = SQL_NTS, num = SQL_NTS, pro = SQL_NTS;
	//输入SQL语句
	ret = InsertSQL(&hstmt1, &hdbc1, sql);
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
	{
		//将数据缓冲区绑定数据库中的相应字段（参数分别表示句柄、列、变量类型、接收缓冲、缓冲长度、返回的长度）
		ret = SQLBindCol(hstmt1, 1, SQL_C_CHAR, 班级编号, 10, &no);
		ret = SQLBindCol(hstmt1, 2, SQL_C_CHAR, 班级名称, 15, &nname);
		ret = SQLBindCol(hstmt1, 3, SQL_C_CHAR, 班主任, 10, &headmaster);
		ret = SQLBindCol(hstmt1, 4, SQL_C_CHAR, 人数, 10, &num);
		ret = SQLBindCol(hstmt1, 5, SQL_C_CHAR, 系别, 10, &pro);
	}
	//遍历数据
	while ((ret = SQLFetch(hstmt1)) != SQL_NO_DATA_FOUND)
	{
		if (ret == SQL_ERROR)
			printf("数据查询出错\n");
		else if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
		{
			printf("班级编号为%s的班主任是%s，班级共有%s人，是%s\n", 班级编号, 班主任, 人数, 系别);
		}
		else
		{
			printf("数据查询出错!\n");
			break;
		}
	}
	
	//释放连接
	DisconnectSQL(&henv, &hdbc1,&hstmt1);
	return 0;
}