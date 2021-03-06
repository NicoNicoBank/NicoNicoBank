
// NicoNicoBankDlg.h: 头文件
//

#pragma once
#include "CUsersDlg.h"	// Added by ClassView
#include "CCheckinfo.h"// Added by ClassView

// CNicoNicoBankDlg 对话框
class CNicoNicoBankDlg : public CDialogEx
{
// 构造
public:
	CNicoNicoBankDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NICONICOBANK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	
//	CUsersDlg m_user;
	afx_msg void OnBnClickedUsers();
	// 也是验证密码和账号
	CCheckinfo infocheck;
	afx_msg void OnBnClickedcheck();
	afx_msg void OnBnClickedaccount();
	void clickindexhide(); //该函数用于隐藏首页的所有按钮与文本框
	void clickindexshow(); //该函数用于显示首页的所有按钮与文本框
	void userhide();//该函数控制的是用户的存取款界面
	void usershow();
	afx_msg void OnStnClickedtitle();
	afx_msg void OnBnClickedadmin();
	afx_msg void OnBnClickedback();
	afx_msg void OnBnClickedsave();
	afx_msg void OnBnClickedWithdrawal();
};
