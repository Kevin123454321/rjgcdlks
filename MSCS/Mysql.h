#pragma once#pragma once
#include <mysql.h>
#include <string>
#include<set>
using namespace std;
class Mysql
{
public:
	/*���캯����ϡ������*/
	Mysql(void);
	~Mysql(void);
	//����
	MYSQL mysql;
	/*
	   ��Ҫ�Ĺ��ܣ�
	   ��ʼ�����ݿ�
	   �������ݿ�
	   �����ַ���

	   ��ڲ�����
	   host ��MYSQL������IP
	   port:���ݿ�˿�
	   Db�����ݿ�����
	   user�����ݿ��û�
	   passwd�����ݿ��û�������
	   charset��ϣ��ʹ�õ��ַ���
	   Msg:���ص���Ϣ������������Ϣ

	   ���ڲ�����
	   int ��0��ʾ�ɹ���1��ʾʧ��
	   */
	int Connmysql(char *host, char * port, char * Db, char *user, char* passwd, char * charset, string & Msg);

	/*
	   ��Ҫ�Ĺ��ܣ�
	   ��ѯ����

	   ��ڲ�����
	   SQL����ѯ��SQL���
	   Cnum:��ѯ������
	   Msg:���ص���Ϣ������������Ϣ

	   ���ڲ�����
	   string ׼�����÷��ص����ݣ�������¼����0x06����,�����λ��0x05����
	   ��� ���صĳ��ȣ� 0�����ʾ�޽��
	   */
	string SelectData(CString & SQL, int Cnum, string & Msg);
	/*
	   ��Ҫ���ܣ�
	   ��������

	   ��ڲ���
	   SQL����ѯ��SQL���
	   Msg:���ص���Ϣ������������Ϣ

	   ���ڲ�����
	   int ��0��ʾ�ɹ���1��ʾʧ��
	   */
	int InsertData(CString & SQL, string & Msg);

	/*
	   ��Ҫ���ܣ�
	   �޸�����

	   ��ڲ���
	   SQL����ѯ��SQL���
	   Msg:���ص���Ϣ������������Ϣ

	   ���ڲ�����
	   int ��0��ʾ�ɹ���1��ʾʧ��
	   */
	int UpdateData(char * SQL, string & Msg);
	/*
	   ��Ҫ���ܣ�
	   ɾ������

	   ��ڲ���
	   SQL����ѯ��SQL���
	   Msg:���ص���Ϣ������������Ϣ

	   ���ڲ�����
	   int ��0��ʾ�ɹ���1��ʾʧ��
	   */
	int DeleteData(char * SQL, string & Msg);
	/*
	   ��Ҫ���ܣ�
	   �ر����ݿ�����
	   */
	void CloseMysqlconn();
	set<string> selectman(char *SQL);
};

