
// calculatorDlg.h : 头文件
//

#pragma once


// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double temp;
	int flag;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClickedclean();
	afx_msg void OnBnClickedchance();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedpoint();
	afx_msg void OnBnClickedadd();
	CString m_str;
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked11();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked10();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClickedride();
	afx_msg void OnBnClickeddiv();
	afx_msg void OnBnClickedsqr();
	afx_msg void OnBnClickedsqu();
	afx_msg void OnBnClickedper();
	afx_msg void OnBnClickedButton5();
};
