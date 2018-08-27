// UsersinfocheckDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "NicoNicoBank.h"
#include "UsersinfocheckDlg.h"
#include "afxdialogex.h"


// UsersinfocheckDlg 对话框

IMPLEMENT_DYNAMIC(UsersinfocheckDlg, CDialogEx)

UsersinfocheckDlg::UsersinfocheckDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USERSINFOCHECK1, pParent)
	, account(_T(""))
	, password(_T(""))
{

}

UsersinfocheckDlg::~UsersinfocheckDlg()
{
}

void UsersinfocheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_account, account);
	DDX_Text(pDX, IDC_password, password);
}


BEGIN_MESSAGE_MAP(UsersinfocheckDlg, CDialogEx)
	ON_EN_CHANGE(IDC_account, &UsersinfocheckDlg::OnEnChangeaccount)
	ON_BN_CLICKED(IDOK, &UsersinfocheckDlg::OnBnClickedOk)
//	ON_NOTIFY(BCN_DROPDOWN, IDOK, &UsersinfocheckDlg::OnAdd)
END_MESSAGE_MAP()


// UsersinfocheckDlg 消息处理程序


void UsersinfocheckDlg::OnEnChangeaccount()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


//
void UsersinfocheckDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(TRUE);
	if (account == "" || password == "")
	{
		AfxMessageBox(_T("不能留有空白项"));
		return;
	}
	
	//接下来返回是否开户，是否冻结的信息，并以弹框形式返回信息
	//Islost
	//Isaccount
	/*if (Islost && Isaccount)
	{
		
	}
	else if (!Isaccount)
	{
		AfxMessageBox(_T("该账户不存在"));
	}
	else if (!Islost)
	{
		AfxMessageBox(_T("该账户已冻结"));
	}
	*/
CDialogEx::OnOK();
}


//void UsersinfocheckDlg::OnAdd(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//}
