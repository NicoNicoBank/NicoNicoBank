// Usersinfocheck2Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "NicoNicoBank.h"
#include "Usersinfocheck2Dlg.h"
#include "afxdialogex.h"


// Usersinfocheck2Dlg 对话框

IMPLEMENT_DYNAMIC(Usersinfocheck2Dlg, CDialogEx)

Usersinfocheck2Dlg::Usersinfocheck2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USERSINFOCHECK2, pParent)
	, password(_T(""))
	, account(_T(""))

{

}

Usersinfocheck2Dlg::~Usersinfocheck2Dlg()
{
}

void Usersinfocheck2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_password, password);
	DDX_Text(pDX, IDC_account, account);
}


BEGIN_MESSAGE_MAP(Usersinfocheck2Dlg, CDialogEx)
END_MESSAGE_MAP()


// Usersinfocheck2Dlg 消息处理程序
