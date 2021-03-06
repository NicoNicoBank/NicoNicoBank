#pragma once


// CaddacinfoDlg 对话框

class CaddacinfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CaddacinfoDlg)

public:
	CaddacinfoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CaddacinfoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDACINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 记录用户存款类型
	int savetype;
	afx_msg void OnBnClickedOk();
	// 记录用户的账户
	CString useraccount;
	// 记录储蓄员账号
	CString workeraccount;
	// 记录用户存储金额
	double amount;
	int year;
	int month;
	int day;
};
