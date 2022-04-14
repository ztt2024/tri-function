// CTipDlg.cpp: 实现文件
//提示界面

#include "pch.h"
#include "MFC_CACL_UI.h"
#include "CTipDlg.h"
#include "afxdialogex.h"


// CTipDlg 对话框

IMPLEMENT_DYNAMIC(CTipDlg, CDialog)

CTipDlg::CTipDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ARCSIN_TIPS, pParent)
{

}

CTipDlg::~CTipDlg()
{
}

void CTipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTipDlg, CDialog)
END_MESSAGE_MAP()


// CTipDlg 消息处理程序
