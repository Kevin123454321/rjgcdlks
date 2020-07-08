#pragma once


// Staff 对话框

class Staff : public CDialogEx
{
	DECLARE_DYNAMIC(Staff)

public:
	Staff(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Staff();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STAFF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
