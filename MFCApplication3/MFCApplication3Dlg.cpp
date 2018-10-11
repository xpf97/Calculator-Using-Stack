
// MFCApplication3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include"Stack.h"
#include"Stacknum.h"
#include<stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
Stack *st = new Stack();
Stacknum *stnum = new Stacknum();
int i = -1;
char arr[100];
bool number = false;
bool cal = false;
bool point = false;
bool left = false;
bool right = false;
int leftnum = 0;
int pointnum = 0;
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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 对话框



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDB_PNG1);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication3Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCApplication3Dlg::OnBnClickedButton18)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication3Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication3Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFCApplication3Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CMFCApplication3Dlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication3Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication3Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication3Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication3Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication3Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication3Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication3Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication3Dlg::OnBnClickedButton16)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 消息处理程序

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	st->Push('#');
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication3Dlg::OnPaint()
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
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

char Precede(char ch1, char ch2)
{
	int i, j;
	char pre[][7] = {
		/*运算符之间的优先级制作成一张表格*/
		{ '>','>','<','<','<','>','>' },
		{ '>','>','<','<','<','>','>' },
		{ '>','>','>','>','<','>','>' },
		{ '>','>','>','>','<','>','>' },
		{ '<','<','<','<','<','=','0' },
		{ '>','>','>','>','0','>','>' },
		{ '<','<','<','<','<','0','=' } };
	switch (ch1) {
	case '+': i = 0; break;
	case '-': i = 1; break;
	case '*': i = 2; break;
	case '/': i = 3; break;
	case '(': i = 4; break;
	case ')': i = 5; break;
	case '#': i = 6; break;
	}
	switch (ch2) {
	case '+': j = 0; break;
	case '-': j = 1; break;
	case '*': j = 2; break;
	case '/': j = 3; break;
	case '(': j = 4; break;
	case ')': j = 5; break;
	case '#': j = 6; break;
	}
	return pre[i][j];
}

double Operate(double num1, char ch, double num2)
{
	double result;
	switch (ch)
	{
	case '+':result = num1 + num2; break;
	case '-':result = num1 - num2; break;
	case '*':result = num1 * num2; break;
	case '/':result = num1 / num2; break;
	}
	return result;
}

void EvluateExpression(char ch)
{
	while (ch != '#' || st->GetTop() != '#')
	{
		switch (Precede(st->GetTop(), ch))
		{
		case '<':st->Push(ch); break;
		case '=':st->Pop(); break;
		case '>':
			double num1 = stnum->Pop();
			double num2 = stnum->Pop();
			char theta = st->Pop();
			stnum->Push(Operate(num2, theta, num1));
			EvluateExpression(ch);
			break;
		}
		break;
	}
}

void CMFCApplication3Dlg::ShowEdit(wchar_t num[])
{
	CString str;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(str);
	str.Append(num);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(str);
}

void Numberinitial()
{
	if (i != -1)
	{
		double temp = atof(arr);
		i = -1;
		for (int j = 0; j < 100; j++)
		{
			arr[j] = 0;
		}
		stnum->Push(temp);
	}
}

void BoolInitial()
{
	number = false;
	cal = false;
	point = false;
	left = false;
	right = false;
}

void CMFCApplication3Dlg::OnBnClickedButton1()
{
	if (right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"1");
	arr[++i] = '1';
	BoolInitial();
	number = true;

	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton2()
{
	if (right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"2");
	arr[++i] = '2';
	BoolInitial();
	number = true;
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton3()
{
	if (right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"3");
	arr[++i] = '3';
	BoolInitial();
	number = true;
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton4()
{
	if (right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"4");
	arr[++i] = '4';
	BoolInitial();
	number = true;
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton5()
{
	if (right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"5");
	arr[++i] = '5';
	BoolInitial();
	number = true;
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton6()
{
	if (right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"6");
	arr[++i] = '6';
	BoolInitial();
	number = true;
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton7()
{
	if (right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"7");
	arr[++i] = '7';
	BoolInitial();
	number = true;
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton8()
{
	if (right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"8");
	arr[++i] = '8';
	BoolInitial();
	number = true;
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton9()
{
	if (right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"9");
	arr[++i] = '9';
	BoolInitial();
	number = true;
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton10()
{
	if (right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"0");
	arr[++i] = '0';
	BoolInitial();
	number = true;
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton11()
{
	if (left == true || cal == true || point == true || (number == false && cal == false && point == false && left == false && right == false))
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"+");
	Numberinitial();
	EvluateExpression('+');
	BoolInitial();
	cal = true;
	pointnum--;

	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton12()
{
	if (left == true || cal == true || point == true || (number == false && cal == false && point == false && left == false && right == false))
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"-");
	Numberinitial();
	EvluateExpression('-');
	BoolInitial();
	cal = true;
	pointnum--;

	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton13()
{
	if (left == true || cal == true || point == true || (number == false && cal == false && point == false && left == false && right == false))
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"*");
	Numberinitial();
	EvluateExpression('*');
	BoolInitial();
	cal = true;
	pointnum--;

	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton14()
{
	if (left == true || cal == true || point == true || (number == false && cal == false && point == false && left == false && right == false))
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"/");
	Numberinitial();
	EvluateExpression('/');
	BoolInitial();
	cal = true;
	pointnum--;

	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton15()
{
	if (left == true || right == true || cal == true || point == true || (number == false && cal == false && point == false && left == false && right == false)||pointnum == 1)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L".");
	arr[++i] = '.';
	BoolInitial();
	point = true;
	pointnum++;
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton16()
{
	if (left == true || cal == true || point == true || (number == false && cal == false && point == false && left == false && right == false) || leftnum != 0)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"=");
	Numberinitial();
	EvluateExpression('#');
	double final = stnum->GetTop();
	CString str;
	str.Format(_T("%.2f"), final);
	edit.SetWindowTextW(str);
	leftnum = 0;
	pointnum = 0;
	// TODO: 在此添加控件通知处理程序代码
}

void CMFCApplication3Dlg::OnBnClickedButton17()
{
	if (number == true || point == true || right == true)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L"(");
	EvluateExpression('(');
	BoolInitial();
	left = true;
	leftnum++;
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton18()
{
	if (left == true || point == true || cal == true || (number == false && cal == false && point == false && left == false && right == false) || leftnum == 0)
	{
		MessageBox(_T("ERROR"), _T("Input Again"), MB_ICONERROR);
		return;
	}
	ShowEdit(L")");
	Numberinitial();
	EvluateExpression(')');
	BoolInitial();
	right = true;
	leftnum--;
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton19()
{
	//%
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedButton20()
{
	CString str = NULL;
	edit.SetWindowTextW(str);
	stnum->Clear();
	BoolInitial();
	leftnum = 0;
	pointnum = 0;
	// TODO: 在此添加控件通知处理程序代码
}