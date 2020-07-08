
// MSCSDlg.cpp: 实现文件
//

#include<Windows.h>
#include<string.h>
#include<winsock2.h>
#include "stdafx.h"
#include"mysql.h"
#include"Mysql.h"
#include"Set.h"
#include "MSCS.h"
#include "MSCSDlg.h"
#include "afxdialogex.h"
#include"Manager.h"
#include"Staff.h"
#pragma comment(lib,"libmysql")
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//数据库
Mysql mysql;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMSCSDlg 对话框



CMSCSDlg::CMSCSDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MSCS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMSCSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMSCSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMSCSDlg::OnBnClickedOk)
	ON_BN_CLICKED(ID_SIGN, &CMSCSDlg::OnBnClickedSign)
END_MESSAGE_MAP()


// CMSCSDlg 消息处理程序

BOOL CMSCSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	//链接数据库
	string msg;
	if(mysql.Connmysql(HOST,PORT,DBNAME,USER,PASSWD,CHARSET,msg)==1)
		MessageBox(msg.c_str());//链接失败则发送错误消息

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMSCSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMSCSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMSCSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMSCSDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString user = "";
	CString password = "";
	string msg;
	GetDlgItem(IDC_EDIT_USER)->GetWindowText(user);
	GetDlgItem(IDC_EDIT_PASSWORD)->GetWindowText(password);
	if (user.GetLength() == 0 || password.GetLength() == 0) {
		MessageBox("用户名或密码不能为空！");
		user = "";
		password = "";
		SetDlgItemText(IDC_EDIT_USER, user);
		SetDlgItemText(IDC_EDIT_PASSWORD, password);
	}
	else {
		CString query;
		string res,msg;
		//mysql_free_result(m_res);
		query.Format("select * from users where username  =  '%s' and password = '%s'", user,password);
		res=mysql.SelectData(query, 4, msg);
		if(res=="")
			MessageBox("用户名或密码错误！");
		else if(res[0]=='0')
		{
			//跳转至管理员界面
			//MessageBox("进入管理界面");
			this->ShowWindow(SW_HIDE);
			Manager Dlg;
			Dlg.DoModal();
			this->ShowWindow(SW_SHOW);
		}
		else
		{
			//跳转至收银员界面
			this->ShowWindow(SW_HIDE);
			Staff Dlg;
			Dlg.DoModal();
			this->ShowWindow(SW_SHOW);
		}
	}
}



void CMSCSDlg::OnBnClickedSign()
{
	// TODO: 在此添加控件通知处理程序代码
	CString user = "";
	CString password = "";
	string msg,res;
	GetDlgItem(IDC_EDIT_USER)->GetWindowText(user);
	GetDlgItem(IDC_EDIT_PASSWORD)->GetWindowText(password);
	if (user.GetLength() == 0 || password.GetLength() == 0) {
		MessageBox("用户名或密码不能为空！");
		user = "";
		password = "";
		SetDlgItemText(IDC_EDIT_USER, user);
		SetDlgItemText(IDC_EDIT_PASSWORD, password);
	}
	else {
		CString query;
		query.Format("select * from users where username  =  '%s'", user);
		res = mysql.SelectData(query, 4, msg);
		if (res != "")
			MessageBox("用户名已被注册！");
		query.Format("insert into users(level,username,password)values(1,'%s','%s')", user, password);
		if (!mysql.InsertData(query, msg))
			MessageBox("注册成功！");
	}
}
