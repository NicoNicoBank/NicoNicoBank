// CaddacinfoDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "NicoNicoBank.h"
#include "CaddacinfoDlg.h"
#include "afxdialogex.h"


// CaddacinfoDlg 对话框

IMPLEMENT_DYNAMIC(CaddacinfoDlg, CDialogEx)

CaddacinfoDlg::CaddacinfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDACINFO, pParent)
	, savetype(-1)
	, useraccount(_T(""))
	, workeraccount(_T(""))
	, amount(0)
	, year(0)
	, month(0)
	, day(0)
{

}

CaddacinfoDlg::~CaddacinfoDlg()
{
}

void CaddacinfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO2, savetype);
	DDX_Text(pDX, IDC_Useraccount, useraccount);
	DDX_Text(pDX, IDC_Workeraccount, workeraccount);
	DDX_Text(pDX, IDC_amount, amount);
	DDX_Text(pDX, IDC_year, year);
	DDX_Text(pDX, IDC_month, month);
	DDV_MinMaxInt(pDX, month, 1, 12);
	DDX_Text(pDX, IDC_day, day);
	DDV_MinMaxInt(pDX, day, 1, 31);
}


BEGIN_MESSAGE_MAP(CaddacinfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CaddacinfoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CaddacinfoDlg 消息处理程序

//提交工单信息
void CaddacinfoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (useraccount == "" || workeraccount == "" || savetype == -1||amount==0||year==0||month==0||day==0)
	{
		AfxMessageBox(_T("不能留有空白项"));
	}
	else
	{
		UpdateData(TRUE);
		//savetype记录选择第几项
		CString message;
	}
	CDialogEx::OnOK();
}
