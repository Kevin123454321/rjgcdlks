#pragma once#pragma once
#include <mysql.h>
#include <string>
#include<set>
using namespace std;
class Mysql
{
public:
	/*构造函数和稀构函数*/
	Mysql(void);
	~Mysql(void);
	//变量
	MYSQL mysql;
	/*
	   主要的功能：
	   初始化数据库
	   连接数据库
	   设置字符集

	   入口参数：
	   host ：MYSQL服务器IP
	   port:数据库端口
	   Db：数据库名称
	   user：数据库用户
	   passwd：数据库用户的密码
	   charset：希望使用的字符集
	   Msg:返回的消息，包括错误消息

	   出口参数：
	   int ：0表示成功；1表示失败
	   */
	int Connmysql(char *host, char * port, char * Db, char *user, char* passwd, char * charset, string & Msg);

	/*
	   主要的功能：
	   查询数据

	   入口参数：
	   SQL：查询的SQL语句
	   Cnum:查询的列数
	   Msg:返回的消息，包括错误消息

	   出口参数：
	   string 准备放置返回的数据，多条记录则用0x06隔开,多个栏位用0x05隔开
	   如果 返回的长度＝ 0，则表示无结果
	   */
	string SelectData(CString & SQL, int Cnum, string & Msg);
	/*
	   主要功能：
	   插入数据

	   入口参数
	   SQL：查询的SQL语句
	   Msg:返回的消息，包括错误消息

	   出口参数：
	   int ：0表示成功；1表示失败
	   */
	int InsertData(CString & SQL, string & Msg);

	/*
	   主要功能：
	   修改数据

	   入口参数
	   SQL：查询的SQL语句
	   Msg:返回的消息，包括错误消息

	   出口参数：
	   int ：0表示成功；1表示失败
	   */
	int UpdateData(char * SQL, string & Msg);
	/*
	   主要功能：
	   删除数据

	   入口参数
	   SQL：查询的SQL语句
	   Msg:返回的消息，包括错误消息

	   出口参数：
	   int ：0表示成功；1表示失败
	   */
	int DeleteData(char * SQL, string & Msg);
	/*
	   主要功能：
	   关闭数据库连接
	   */
	void CloseMysqlconn();
	set<string> selectman(char *SQL);
};

