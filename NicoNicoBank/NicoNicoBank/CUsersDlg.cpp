// CUsersDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "NicoNicoBank.h"
#include "CUsersDlg.h"
#include "afxdialogex.h"


// CUsersDlg 对话框

IMPLEMENT_DYNAMIC(CUsersDlg, CDialogEx)

CUsersDlg::CUsersDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USERS, pParent)
{

}

CUsersDlg::~CUsersDlg()
{
}

void CUsersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUsersDlg, CDialogEx)
	ON_BN_CLICKED(users_save, &CUsersDlg::OnBnClickedsave)
	ON_BN_CLICKED(users_Withdrawal, &CUsersDlg::OnBnClickedWithdrawal)
END_MESSAGE_MAP()


// CUsersDlg 消息处理程序


void CUsersDlg::OnBnClickedsave()
{
	// TODO: 在此添加控件通知处理程序代码
	user_checkinfo1.password = "";
	user_checkinfo1.account = "";
	if (user_checkinfo1.DoModal() == IDOK)
	{

	}
}


void CUsersDlg::OnBnClickedWithdrawal()
{
	// TODO: 在此添加控件通知处理程序代码
	user_checkinfo2.password = "";
	user_checkinfo2.account = "";
	if (user_checkinfo2.DoModal() == IDOK)
	{

	}
}
