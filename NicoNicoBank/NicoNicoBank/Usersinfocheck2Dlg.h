#pragma once


// Usersinfocheck2Dlg 对话框

class Usersinfocheck2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Usersinfocheck2Dlg)

public:
	Usersinfocheck2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Usersinfocheck2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERSINFOCHECK2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CString password;
//	CString password;
//	CString account;
	CString password;
	CString account;
};
