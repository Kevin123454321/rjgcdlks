// Manager.cpp: 实现文件
//

#include "stdafx.h"
//#include "pch.h"
#include "MSCS.h"
#include "Manager.h"
#include "afxdialogex.h"


// Manager 对话框

IMPLEMENT_DYNAMIC(Manager, CDialogEx)

Manager::Manager(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MANAGER, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

Manager::~Manager()
{
}

void Manager::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Manager, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_VIPID, &Manager::OnEnChangeEditVipid)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, &Manager::OnLvnItemchangedList)
END_MESSAGE_MAP()


// Manager 消息处理程序


void Manager::OnEnChangeEditVipid()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}




void Manager::OnLvnItemchangedList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
