#pragma once


// SUMMAND_PAGE 对话框

class SUMMAND_PAGE : public CPropertyPage
{
	DECLARE_DYNAMIC(SUMMAND_PAGE)

public:
	SUMMAND_PAGE();
	virtual ~SUMMAND_PAGE();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUMMAND_PAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
