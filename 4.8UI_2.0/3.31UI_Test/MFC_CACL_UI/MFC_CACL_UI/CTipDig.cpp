// CTipDig.cpp: 实现文件
//

#include "pch.h"
#include "MFC_CACL_UI.h"
#include "CTipDig.h"
#include "afxdialogex.h"


// CTipDig 对话框

IMPLEMENT_DYNAMIC(CTipDig, CDialogEx)

CTipDig::CTipDig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CTipDig::~CTipDig()
{
}

void CTipDig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTipDig, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CTipDig::OnBnClickedCancel)
END_MESSAGE_MAP()


// CTipDig 消息处理程序


void CTipDig::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
