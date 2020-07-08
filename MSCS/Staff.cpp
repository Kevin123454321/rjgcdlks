// Staff.cpp: 实现文件
//

#include "stdafx.h"
//#include "pch.h"
#include "MSCS.h"
#include "Staff.h"
#include "afxdialogex.h"


// Staff 对话框

IMPLEMENT_DYNAMIC(Staff, CDialogEx)

Staff::Staff(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_STAFF, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

Staff::~Staff()
{
}

void Staff::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Staff, CDialogEx)
END_MESSAGE_MAP()


// Staff 消息处理程序
