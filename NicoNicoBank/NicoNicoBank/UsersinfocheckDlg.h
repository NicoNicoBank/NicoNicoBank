#pragma once


// UsersinfocheckDlg 对话框

class UsersinfocheckDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UsersinfocheckDlg)

public:
	UsersinfocheckDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~UsersinfocheckDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERSINFOCHECK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeaccount();
	// 这是用户的账户
	CString account;
	// 这是用户的密码
	CString password;
	afx_msg void OnBnClickedOk();
//	afx_msg void OnAdd(NMHDR *pNMHDR, LRESULT *pResult);
};
