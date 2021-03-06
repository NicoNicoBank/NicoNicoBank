#pragma once


// CCheckinfo 对话框

class CCheckinfo : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckinfo)

public:
	CCheckinfo(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCheckinfo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHECKINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString account;
	afx_msg void OnEnChangepassword();
	CString password;
	afx_msg void OnEnChangetitle();
	CString check_title;
};
