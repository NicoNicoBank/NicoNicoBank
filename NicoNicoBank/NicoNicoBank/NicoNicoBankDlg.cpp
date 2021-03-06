
// NicoNicoBankDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "NicoNicoBank.h"
#include "NicoNicoBankDlg.h"
#include "afxdialogex.h"
//#include "User.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CNicoNicoBankDlg 对话框



CNicoNicoBankDlg::CNicoNicoBankDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NICONICOBANK_DIALOG, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNicoNicoBankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNicoNicoBankDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(index_Users, &CNicoNicoBankDlg::OnBnClickedUsers)
	ON_BN_CLICKED(index_check, &CNicoNicoBankDlg::OnBnClickedcheck)
	ON_BN_CLICKED(index_account, &CNicoNicoBankDlg::OnBnClickedaccount)
	//ON_STN_CLICKED(index_title, &CNicoNicoBankDlg::OnStnClickedtitle)
	ON_BN_CLICKED(index_admin, &CNicoNicoBankDlg::OnBnClickedadmin)
	ON_BN_CLICKED(IDC_back, &CNicoNicoBankDlg::OnBnClickedback)
	ON_BN_CLICKED(users_save, &CNicoNicoBankDlg::OnBnClickedsave)
	ON_BN_CLICKED(users_Withdrawal, &CNicoNicoBankDlg::OnBnClickedWithdrawal)
END_MESSAGE_MAP()


// CNicoNicoBankDlg 消息处理程序

BOOL CNicoNicoBankDlg::OnInitDialog()
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

	// TODO: 在此添加额外的初始化代码
	//Date d1(1, 1, 1);
	//Date d2(1, 1, 1);
	//string a = "test";
	//User user(a,a,a,a,a,d1,false,d2,1);
	//user.save();
	//string a = user.sqlread(1);
	//string b = "123";
	//CString cst(b.c_str());
	//test = cst;
	//UpdateData(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CNicoNicoBankDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNicoNicoBankDlg::OnPaint()
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
HCURSOR CNicoNicoBankDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//显示第二副主页
void CNicoNicoBankDlg::usershow()
{
	
	CEdit *title2 = (CEdit*)GetDlgItem(user_title);
	title2->ShowWindow(TRUE); 
	CEdit *withdrawal = (CEdit*)GetDlgItem(users_Withdrawal);
	withdrawal->ShowWindow(TRUE);
	CEdit *save = (CEdit*)GetDlgItem(users_save);
	save->ShowWindow(TRUE);
	CEdit *back = (CEdit*)GetDlgItem(IDC_back);
	back->ShowWindow(TRUE);

}

//隐藏第二副主页
void CNicoNicoBankDlg::userhide()
{

	CEdit *title2 = (CEdit*)GetDlgItem(user_title);
	title2->ShowWindow(FALSE);
	CEdit *withdrawal = (CEdit*)GetDlgItem(users_Withdrawal);
	withdrawal->ShowWindow(FALSE);
	CEdit *save = (CEdit*)GetDlgItem(users_save);
	save->ShowWindow(FALSE);
	CEdit *back = (CEdit*)GetDlgItem(IDC_back);
	back->ShowWindow(FALSE);

}

//隐藏首页
void CNicoNicoBankDlg::clickindexhide()
{
	CEdit *title = (CEdit*)GetDlgItem(index_title);
	title->ShowWindow(FALSE); //隐藏该控件
	CEdit *user = (CEdit*)GetDlgItem(index_Users);
	user->ShowWindow(FALSE); //隐藏该控件
	CEdit *check = (CEdit*)GetDlgItem(index_check);
	check->ShowWindow(FALSE); //隐藏该控件
	CEdit *account = (CEdit*)GetDlgItem(index_account);
	account->ShowWindow(FALSE); //隐藏该控件
	CEdit *admin = (CEdit*)GetDlgItem(index_admin);
	admin->ShowWindow(FALSE); //隐藏该控件

}
//显示首页
void CNicoNicoBankDlg::clickindexshow()
{
	CEdit *title = (CEdit*)GetDlgItem(index_title);
	title->ShowWindow(TRUE);
	CEdit *user = (CEdit*)GetDlgItem(index_Users);
	user->ShowWindow(TRUE); 
	CEdit *check = (CEdit*)GetDlgItem(index_check);
	check->ShowWindow(TRUE); 
	CEdit *account = (CEdit*)GetDlgItem(index_account);
	account->ShowWindow(TRUE); 
	CEdit *admin = (CEdit*)GetDlgItem(index_admin);
	admin->ShowWindow(TRUE); 

}
void CNicoNicoBankDlg::OnBnClickedUsers()
{
	// TODO: 在此添加控件通知处理程序代码
	//隐藏主页的原有按钮	
	clickindexhide();
	usershow();
	/*if (m_user.DoModal() == IDOK)
	{

	}*/


}


void CNicoNicoBankDlg::OnBnClickedcheck()
{
	// TODO: 在此添加控件通知处理程序代码
	infocheck.account = "";
	infocheck.password = "";
	infocheck.check_title = "信息查询";
	if (infocheck.DoModal() == IDOK)
	{
		
	}

}


void CNicoNicoBankDlg::OnBnClickedaccount()
{
	// TODO: 在此添加控件通知处理程序代码
	clickindexhide();
	
}



void CNicoNicoBankDlg::OnBnClickedadmin()
{
	// TODO: 在此添加控件通知处理程序代码
//	test1.DoModal();
}

//点击副主页的主屏键
void CNicoNicoBankDlg::OnBnClickedback()
{
	// TODO: 在此添加控件通知处理程序代码
	userhide();
	clickindexshow();

	
}


void CNicoNicoBankDlg::OnBnClickedsave()
{
	// TODO: 在此添加控件通知处理程序代码
	infocheck.account = "";
	infocheck.password = "";
	infocheck.check_title = "存款";
	if (infocheck.DoModal() == IDOK)
	{

	}

}


void CNicoNicoBankDlg::OnBnClickedWithdrawal()
{
	// TODO: 在此添加控件通知处理程序代码
	infocheck.account = "";
	infocheck.password = "";
	infocheck.check_title = "取款";
	if (infocheck.DoModal() == IDOK)
	{

	}

}
