
// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include"math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg �Ի���




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_clean, &CcalculatorDlg::OnBnClickedclean)
	ON_BN_CLICKED(IDC_chance, &CcalculatorDlg::OnBnClickedchance)
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_point, &CcalculatorDlg::OnBnClickedpoint)
	ON_BN_CLICKED(IDC_add, &CcalculatorDlg::OnBnClickedadd)
//	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_11, &CcalculatorDlg::OnBnClicked11)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_10, &CcalculatorDlg::OnBnClicked10)
	ON_BN_CLICKED(IDC_minus, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_ride, &CcalculatorDlg::OnBnClickedride)
	ON_BN_CLICKED(IDC_div, &CcalculatorDlg::OnBnClickeddiv)
	ON_BN_CLICKED(IDC_sqr, &CcalculatorDlg::OnBnClickedsqr)	
	//ON_BN_CLICKED(IDC_squ, &CcalculatorDlg::OnBnClickedsqu)
	ON_BN_CLICKED(IDC_squ, &CcalculatorDlg::OnBnClickedsqu)
	ON_BN_CLICKED(IDC_per, &CcalculatorDlg::OnBnClickedper)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CcalculatorDlg::OnBnClicked1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������	
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedclean()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	UpdateData(true);
	temp=_ttof(m_str);
	m_str=L"";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedchance()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TRACE(L"flag=%d",flag);
	UpdateData(true);
	if(flag==1)
	{
		temp=temp+_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==2)
	{
		temp=temp-_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==3)
	{
		temp=temp*_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==4)
	{
		if(_ttof(m_str)==0)
		{
			m_str.Format(L"error");
		}
		else{
			temp=temp/_ttof(m_str);
			m_str.Format(L"%lf",temp);
		}
	}
	if(flag==5)
	{
		temp=sqrt(_ttof(m_str));
		m_str.Format(L"%lf",temp);
	}
	if(flag==6)
	{
		temp=_ttof(m_str)*_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==7)
	{
		temp=_ttof(m_str)/100;
		m_str.Format(L"%lf",temp);
	}
	if(flag==8)
	{
		temp=0-temp;
		m_str.Format(L"%lf",temp);
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);	
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedpoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(m_str.Find(L".")==-1)
		m_str=m_str+L".";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}



void CcalculatorDlg::OnBnClicked5()
{
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClicked11()
{
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClicked6()
{
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClicked8()
{
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClicked9()
{
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClicked10()
{
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClicked7()
{
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedride()
{
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickeddiv()
{
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalculatorDlg::OnBnClickedsqr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    flag=5;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


/*void CcalculatorDlg::OnBnClickedsqu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    flag=6;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}*/


void CcalculatorDlg::OnBnClickedsqu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=6;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedper()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=7;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=8;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}
