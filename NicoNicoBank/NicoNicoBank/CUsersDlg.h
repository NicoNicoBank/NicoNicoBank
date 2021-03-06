#pragma once
#include "UsersinfocheckDlg.h"
#include "Usersinfocheck2Dlg.h"
// CUsersDlg 对话框

class CUsersDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUsersDlg)

public:
	CUsersDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CUsersDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 用户信息确认
	UsersinfocheckDlg user_checkinfo1;
	afx_msg void OnBnClickedsave();
	Usersinfocheck2Dlg user_checkinfo2;
	afx_msg void OnBnClickedWithdrawal();
};
