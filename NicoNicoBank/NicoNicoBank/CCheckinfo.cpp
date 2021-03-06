// CCheckinfo.cpp: 实现文件
//

#include "stdafx.h"
#include "NicoNicoBank.h"
#include "CCheckinfo.h"
#include "afxdialogex.h"


// CCheckinfo 对话框

IMPLEMENT_DYNAMIC(CCheckinfo, CDialogEx)

CCheckinfo::CCheckinfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHECKINFO, pParent)
	, account(_T(""))
	, password(_T(""))
	, check_title(_T(""))
{

}

CCheckinfo::~CCheckinfo()
{
}

void CCheckinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_account, account);
	DDX_Text(pDX, IDC_password, password);
	DDX_Text(pDX, checkinfo_title, check_title);
}


BEGIN_MESSAGE_MAP(CCheckinfo, CDialogEx)
	ON_EN_CHANGE(IDC_password, &CCheckinfo::OnEnChangepassword)
	ON_EN_CHANGE(checkinfo_title, &CCheckinfo::OnEnChangetitle)
END_MESSAGE_MAP()


// CCheckinfo 消息处理程序


void CCheckinfo::OnEnChangepassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCheckinfo::OnEnChangetitle()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
