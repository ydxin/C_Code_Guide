#ifndef  _CHAPTER19_H_
#define _CHAPTER19_H_

#include <string.h>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>

#define  SQL_LENGTH  200
#define SET_STMT_ATTR
#define SQLDRIVERCONNECT 
void ConnectSQL(SQLHENV *henv, SQLHDBC *hdbc);
void DisconnectSQL(SQLHENV* henv, SQLHDBC* hdbc, SQLHSTMT* hstmt);
SQLRETURN InsertSQL(SQLHSTMT *hstmt, SQLHDBC *hdbc, UCHAR *sqlarr);
#endif // ! _CHAPTER19_H_
