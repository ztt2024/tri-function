// SUMMAND_PAGE.cpp: 实现文件
//

#include "pch.h"
#include "Addition.h"
#include "SUMMAND_PAGE.h"
#include "afxdialogex.h"


// SUMMAND_PAGE 对话框

IMPLEMENT_DYNAMIC(SUMMAND_PAGE, CPropertyPage)

SUMMAND_PAGE::SUMMAND_PAGE()
	: CPropertyPage(IDD_SUMMAND_PAGE)
{

}

SUMMAND_PAGE::~SUMMAND_PAGE()
{
}

void SUMMAND_PAGE::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SUMMAND_PAGE, CPropertyPage)
END_MESSAGE_MAP()


// SUMMAND_PAGE 消息处理程序


BOOL SUMMAND_PAGE::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	// 获得父窗口，即属性表CPropertySheet类   
	CPropertySheet* psheet = (CPropertySheet*)GetParent();
	// 设置属性表只有“下一步”按钮   
	psheet->SetWizardButtons(PSWIZB_NEXT);
 
	return CPropertyPage::OnSetActive();
}
