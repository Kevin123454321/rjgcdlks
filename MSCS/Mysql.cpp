#include "StdAfx.h"
#include "Mysql.h"
#include <set>
#include <cstdlib>
using namespace std;
Mysql::Mysql(void)
{
}


Mysql::~Mysql(void)
{
}
//初始化数据
int Mysql::Connmysql(char *host, char * port, char * Db, char *user, char * passwd, char * charset, string & Msg)
{
	if (mysql_init(&mysql) == NULL)
	{
		//Msg = "inital mysql handle error";
		Msg = "初始化mysql句柄错误！";
		return 1;
	}
	if (!mysql_real_connect(&mysql, host, user, passwd, Db, 0, NULL, 0))
	{
		//Msg = "Failed to connect to database:Error";
		Msg = "错误：连接数据库失败！";
		return 1;
	}
	if (mysql_set_character_set(&mysql, "GBK") != 0)
	{
		//Msg = "mysql_set_character_set Error";
		Msg = "错误：字符集设置错误！";
		return 1;
	}
	return 0;
}

int Mysql::InsertData(CString &SQL, string & Msg)
{
	if (mysql_query(&mysql, SQL) != 0)
	{
		Msg = "Insert Data Error";
		return 1;
	}
	return 0;
}
int Mysql::DeleteData(char *SQL, string & Msg)
{
	char sql[2048];
	sprintf_s(sql, SQL);
	if (mysql_query(&mysql, sql) != 0)
	{
		Msg = "Delete Data Error";
		return 1;
	}
	return 0;
}
int Mysql::UpdateData(char *SQL, string & Msg)
{
	char sql[2048];
	sprintf_s(sql, SQL);
	if (mysql_query(&mysql, sql) != 0)
	{
		Msg = "Update Data error";
		return 1;
	}
	return 0;
}
string Mysql::SelectData(CString & SQL, int Cnum, string & Msg)
{
	MYSQL_ROW m_row;
	MYSQL_RES *m_res;
	int rnum = 0;
	char rg = '@';
	char cg = '$';
	if (mysql_query(&mysql, SQL) != 0)
	{
		Msg = "select ps_info Error";
		return "";
	}
	m_res = mysql_store_result(&mysql);
	if (m_res == NULL)
	{
		Msg = "select username Error";
		return "";
	}
	string str("");
	while (m_row = mysql_fetch_row(m_res))
	{
		for (int i = 0; i < Cnum; i++)
		{
			str += m_row[i];
			str += cg;
		}
		str += rg;
		rnum++;
	}
	mysql_free_result(m_res);
	return str;
}
void Mysql::CloseMysqlconn()
{
	mysql_close(&mysql);
}
set<string> Mysql::selectman(char *SQL)
{
	MYSQL_ROW m_row;
	MYSQL_RES *m_res;
	char sql[2048];
	sprintf_s(sql, SQL);
	set<string>manset;
	if (mysql_query(&mysql, sql) != 0)
	{
		return manset;
	}
	m_res = mysql_store_result(&mysql);
	if (m_res == NULL)
	{
		return manset;
	}
	while (m_row = mysql_fetch_row(m_res))
	{
		manset.insert(m_row[0]);
	}
	mysql_free_result(m_res);
	return manset;
}