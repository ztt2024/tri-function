
// MFC_CACL_UIDlg.cpp: 实现文件
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "framework.h"
#include "MFC_CACL_UI.h"
#include "MFC_CACL_UIDlg.h"
#include "afxdialogex.h"
#include"calc.h"
constexpr auto PI = 3.1415926;
int state = 0;
double input = 0;
double output = 0;
int input_num = 0;
int dot_state = 0;
CString result;
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
public:
	afx_msg void OnBnClickedButton3();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_3, &CAboutDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCCACLUIDlg 对话框



CMFCCACLUIDlg::CMFCCACLUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CACL_UI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCACLUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SIN_CACL, m_btnedit_sin);
	DDX_Control(pDX, IDC_COS_CACL, m_btnedit_cos);
	DDX_Control(pDX, IDC_ARCSIN_CACL, m_btnedit_arcsin);
	DDX_Control(pDX, IDC_ARCTAN_CACL, m_btnedit_arctan);
	DDX_Control(pDX, IDC_BUTTON_1, m_btnedit_1);
	DDX_Control(pDX, IDC_BUTTON_2, m_btnedit_2);
	DDX_Control(pDX, IDC_BUTTON_3, m_btnedit_3);
	DDX_Control(pDX, IDC_BUTTON_4, m_btnedit_4);
	DDX_Control(pDX, IDC_BUTTON_5, m_btnedit_5);
	DDX_Control(pDX, IDC_BUTTON_6, m_btnedit_6);
	DDX_Control(pDX, IDC_BUTTON_7, m_btnedit_7);
	DDX_Control(pDX, IDC_BUTTON_8, m_btnedit_8);
	DDX_Control(pDX, IDC_BUTTON_9, m_btnedit_9);
	DDX_Control(pDX, IDC_BUTTON_0, m_btnedit_0);

	DDX_Control(pDX, IDC_BUTTON_D, m_btnedit_d);
}

BEGIN_MESSAGE_MAP(CMFCCACLUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SIN_CACL, &CMFCCACLUIDlg::OnBnClickedSinCacl)
	ON_BN_CLICKED(IDC_COS_CACL, &CMFCCACLUIDlg::OnBnClickedCosCacl)
	ON_BN_CLICKED(IDC_ARCSIN_CACL, &CMFCCACLUIDlg::OnBnClickedArcsinCacl)
	ON_BN_CLICKED(IDC_ARCTAN_CACL, &CMFCCACLUIDlg::OnBnClickedArctanCacl)
	ON_BN_CLICKED(IDC_BUTTON_MYDEL, &CMFCCACLUIDlg::OnBnClickedButtonMydel)
	ON_BN_CLICKED(IDC_BUTTON_D, &CMFCCACLUIDlg::OnBnClickedButtonD)
	ON_BN_CLICKED(IDC_BUTTON_2, &CMFCCACLUIDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_1, &CMFCCACLUIDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_4, &CMFCCACLUIDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CMFCCACLUIDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CMFCCACLUIDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CMFCCACLUIDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CMFCCACLUIDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CMFCCACLUIDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, &CMFCCACLUIDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_3, &CMFCCACLUIDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CMFCCACLUIDlg::OnBnClickedButtonResult)
END_MESSAGE_MAP()


// CMFCCACLUIDlg 消息处理程序

BOOL CMFCCACLUIDlg::OnInitDialog()
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
	m_btnedit_0.EnableWindow(0);//按钮不可用
	m_btnedit_1.EnableWindow(0);//按钮不可用
	m_btnedit_2.EnableWindow(0);//按钮不可用
	m_btnedit_3.EnableWindow(0);//按钮不可用
	m_btnedit_4.EnableWindow(0);//按钮不可用
	m_btnedit_5.EnableWindow(0);//按钮不可用
	m_btnedit_6.EnableWindow(0);//按钮不可用
	m_btnedit_7.EnableWindow(0);//按钮不可用
	m_btnedit_8.EnableWindow(0);//按钮不可用
	m_btnedit_9.EnableWindow(0);//按钮不可用
	m_btnedit_d.EnableWindow(0);//按钮不可用
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCCACLUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCCACLUIDlg::OnPaint()
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
HCURSOR CMFCCACLUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






















void CMFCCACLUIDlg::Num_usable() {
	// TODO: 在此添加额外的初始化代码
	m_btnedit_0.EnableWindow(1);//按钮不可用
	m_btnedit_1.EnableWindow(1);//按钮不可用
	m_btnedit_2.EnableWindow(1);//按钮不可用
	m_btnedit_3.EnableWindow(1);//按钮不可用
	m_btnedit_4.EnableWindow(1);//按钮不可用
	m_btnedit_5.EnableWindow(1);//按钮不可用
	m_btnedit_6.EnableWindow(1);//按钮不可用
	m_btnedit_7.EnableWindow(1);//按钮不可用
	m_btnedit_8.EnableWindow(1);//按钮不可用
	m_btnedit_9.EnableWindow(1);//按钮不可用
	m_btnedit_d.EnableWindow(1);//按钮不可用

}
void CMFCCACLUIDlg::Num_unsable() {
	// TODO: 在此添加额外的初始化代码
	m_btnedit_0.EnableWindow(0);//按钮不可用
	m_btnedit_1.EnableWindow(0);//按钮不可用
	m_btnedit_2.EnableWindow(0);//按钮不可用
	m_btnedit_3.EnableWindow(0);//按钮不可用
	m_btnedit_4.EnableWindow(0);//按钮不可用
	m_btnedit_5.EnableWindow(0);//按钮不可用
	m_btnedit_6.EnableWindow(0);//按钮不可用
	m_btnedit_7.EnableWindow(0);//按钮不可用
	m_btnedit_8.EnableWindow(0);//按钮不可用
	m_btnedit_9.EnableWindow(0);//按钮不可用
	m_btnedit_d.EnableWindow(0);//按钮不可用

}


void CMFCCACLUIDlg::OnBnClickedSinCacl()
{
	Num_usable();
	dot_state = 0;
	input_num = 0;
	if (result == "sin")
		input = 0.0;
	result = "";
	m_btnedit_cos.EnableWindow(0);//按钮不可用
	m_btnedit_arcsin.EnableWindow(0);//按钮不可用
	m_btnedit_arctan.EnableWindow(0);//按钮不可用
	// TODO: 在此添加控件通知处理程序代码
	state = 1;
	result += "sin";
	SetDlgItemText(IDC_EDIT_RESULT, result);
}


void CMFCCACLUIDlg::OnBnClickedCosCacl()
{
	Num_usable();
	dot_state = 0;
	input_num = 0;
	if (result == "cos")
		input = 0.0;
	result = "";
	// TODO: 在此添加控件通知处理程序代码
	m_btnedit_sin.EnableWindow(0);//按钮不可用
	m_btnedit_arcsin.EnableWindow(0);//按钮不可用
	m_btnedit_arctan.EnableWindow(0);//按钮不可用
	state = 2;
	result += "cos";
	SetDlgItemText(IDC_EDIT_RESULT, result);
}


void CMFCCACLUIDlg::OnBnClickedArcsinCacl()
{
	Num_usable();
	dot_state = 0;
	input_num = 0;
	if (result == "arcsin")
		input = 0.0;
	result = "";
	// TODO: 在此添加控件通知处理程序代码
	m_btnedit_sin.EnableWindow(0);//按钮不可用
	m_btnedit_cos.EnableWindow(0);//按钮不可用
	m_btnedit_arctan.EnableWindow(0);//按钮不可用
	state = 3;
	result += "arcsin";
	SetDlgItemText(IDC_EDIT_RESULT, result);
}


void CMFCCACLUIDlg::OnBnClickedArctanCacl()
{
	Num_usable();
	dot_state = 0;
	input_num = 0;
	if (result == "arctan")
		input = 0.0;
	result = "";
	// TODO: 在此添加控件通知处理程序代码
	m_btnedit_sin.EnableWindow(0);//按钮不可用
	m_btnedit_cos.EnableWindow(0);//按钮不可用
	m_btnedit_arcsin.EnableWindow(0);//按钮不可用
	state = 4;
	result += "arctan";
	SetDlgItemText(IDC_EDIT_RESULT, result);
}




void CMFCCACLUIDlg::OnBnClickedButtonMydel()
{
	// TODO: 在此添加控件通知处理程序代码
	m_btnedit_sin.EnableWindow(1);//按钮不可用
	m_btnedit_cos.EnableWindow(1);//按钮不可用
	m_btnedit_arcsin.EnableWindow(1);//按钮不可用
	m_btnedit_arctan.EnableWindow(1);//按钮不可用
	Num_unsable();
	input = 0.0;

}




void CMFCCACLUIDlg::OnBnClickedButtonD()
{
	// TODO: 在此添加控件通知处理程序代码
	dot_state = 1;
}


void CMFCCACLUIDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	if (dot_state == 0) {
		input = (input * 10) + 2;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if (dot_state == 1)
	{
		double temp = 2.0;
		input_num++;
		int i = 0;
		while (input_num > i) {
			temp = temp * 0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
}


void CMFCCACLUIDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dot_state == 0) {
		input = (input * 10) + 1;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if(dot_state == 1)
	{
		double temp = 1.0;
		input_num++;
		int i = 0;
		while (input_num>i) {
			temp = temp*0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	
}


void CAboutDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dot_state == 0) {
		input = (input * 10) + 3;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if (dot_state == 1)
	{
		double temp = 3.0;
		input_num++;
		int i = 0;
		while (input_num > i) {
			temp = temp * 0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
}


void CMFCCACLUIDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dot_state == 0) {
		input = (input * 10) + 4;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if (dot_state == 1)
	{
		double temp = 4.0;
		input_num++;
		int i = 0;
		while (input_num > i) {
			temp = temp * 0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
}


void CMFCCACLUIDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dot_state == 0) {
		input = (input * 10) + 5;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if (dot_state == 1)
	{
		double temp = 5.0;
		input_num++;
		int i = 0;
		while (input_num > i) {
			temp = temp * 0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
}


void CMFCCACLUIDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dot_state == 0) {
		input = (input * 10) + 6;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if (dot_state == 1)
	{
		double temp = 6.0;
		input_num++;
		int i = 0;
		while (input_num > i) {
			temp = temp * 0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
}


void CMFCCACLUIDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dot_state == 0) {
		input = (input * 10) + 7;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if (dot_state == 1)
	{
		double temp = 7.0;
		input_num++;
		int i = 0;
		while (input_num > i) {
			temp = temp * 0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
}


void CMFCCACLUIDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dot_state == 0) {
		input = (input * 10) + 8;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if (dot_state == 1)
	{
		double temp = 8.0;
		input_num++;
		int i = 0;
		while (input_num > i) {
			temp = temp * 0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
}


void CMFCCACLUIDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dot_state == 0) {
		input = (input * 10) + 9;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if (dot_state == 1)
	{
		double temp = 9.0;
		input_num++;
		int i = 0;
		while (input_num > i) {
			temp = temp * 0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
}


void CMFCCACLUIDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dot_state == 0) {
		input = (input * 10) + 0;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if (dot_state == 1)
	{
		double temp = 0.0;
		input_num++;
		int i = 0;
		while (input_num > i) {
			temp = temp * 0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
}


void CMFCCACLUIDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dot_state == 0) {
		input = (input * 10) + 3;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
	if (dot_state == 1)
	{
		double temp = 3.0;
		input_num++;
		int i = 0;
		while (input_num > i) {
			temp = temp * 0.1;
			i++;
		}
		input = input + temp;
		CString str;
		str.Format(_T("%lf"), input);
		SetDlgItemText(IDC_EDIT_RESULT, result + str);
	}
}


void CMFCCACLUIDlg::OnBnClickedButtonResult()
{
	CString str_input;
	CString str_output;
	dot_state = 0;
	input_num = 0;
	//output = snowsin(input);
	//str_input.Format(_T("%lf"), input);
	//double xx = snowsin(input);
	//int a = 123;
	//TRACE("%d+++++++++++++++++++++++++++++++++++++++++++\n", xx);
	//str_output.Format(_T("%f"), xx);
	//SetDlgItemText(IDC_EDIT_RESULT, str_output);
	// TODO: 在此添加控件通知处理程序代码
	switch (state)
	{
	case 1:
		output = snowsin(input);
		str_input.Format(_T("%lf"), input);
		str_output.Format(_T("%lf"), output);
		SetDlgItemText(IDC_EDIT_RESULT, result + str_input + "=" +str_output);
		break;
	case 2:
		output = snowcos(input);
		str_input.Format(_T("%lf"), input);
		str_output.Format(_T("%lf"), output);
		SetDlgItemText(IDC_EDIT_RESULT, result + str_input + "=" + str_output);
		break;
	case 3:
		output = snowarcsin(input);
		str_input.Format(_T("%lf"), input);
		str_output.Format(_T("%lf"), output);
		SetDlgItemText(IDC_EDIT_RESULT, result + str_input + "=" + str_output);
		break;
	case 4:
		output = snowarctan(input);
		str_input.Format(_T("%lf"), input);
		str_output.Format(_T("%lf"), output);
		SetDlgItemText(IDC_EDIT_RESULT, result + str_input + "=" + str_output);
		break;
	default:
		break;
	}
}
