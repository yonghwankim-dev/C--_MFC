
// Chapter05_CaculatorDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter05_Caculator.h"
#include "Chapter05_CaculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CChapter05CaculatorDlg 대화 상자



CChapter05CaculatorDlg::CChapter05CaculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER05_CACULATOR_DIALOG, pParent)
	, m_strLed(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter05CaculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LED, m_strLed);
}

BEGIN_MESSAGE_MAP(CChapter05CaculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_9, &CChapter05CaculatorDlg::OnClickedButt9)
	ON_BN_CLICKED(IDC_BUTT_8, &CChapter05CaculatorDlg::OnClickedButt8)
	ON_BN_CLICKED(IDC_BUTT_7, &CChapter05CaculatorDlg::OnClickedButt7)
	ON_BN_CLICKED(IDC_BUTT_6, &CChapter05CaculatorDlg::OnClickedButt6)
	ON_BN_CLICKED(IDC_BUTT_5, &CChapter05CaculatorDlg::OnClickedButt5)
	ON_BN_CLICKED(IDC_BUTT_4, &CChapter05CaculatorDlg::OnClickedButt4)
	ON_BN_CLICKED(IDC_BUTT_3, &CChapter05CaculatorDlg::OnClickedButt3)
	ON_BN_CLICKED(IDC_BUTT_2, &CChapter05CaculatorDlg::OnClickedButt2)
	ON_BN_CLICKED(IDC_BUTT_1, &CChapter05CaculatorDlg::OnClickedButt1)
	ON_BN_CLICKED(IDC_BUTT_0, &CChapter05CaculatorDlg::OnClickedButt0)
	ON_BN_CLICKED(IDC_BUTT_ADD, &CChapter05CaculatorDlg::OnClickedButtAdd)
	ON_BN_CLICKED(IDC_BUTT_DIV, &CChapter05CaculatorDlg::OnClickedButtDiv)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter05CaculatorDlg::OnClickedButtExit)
	ON_BN_CLICKED(IDC_BUTT_MUL, &CChapter05CaculatorDlg::OnClickedButtMul)
	ON_BN_CLICKED(IDC_BUTT_RESULT, &CChapter05CaculatorDlg::OnClickedButtResult)
	ON_BN_CLICKED(IDC_BUTT_SUB, &CChapter05CaculatorDlg::OnClickedButtSub)
	ON_BN_CLICKED(IDC_BUTT_ZERO, &CChapter05CaculatorDlg::OnClickedButtZero)
END_MESSAGE_MAP()


// CChapter05CaculatorDlg 메시지 처리기

BOOL CChapter05CaculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_iCal = 0;
	m_iOne = 0;
	m_iTwo = 0;
	m_iSwitch = 0;
	m_strLed = "";
	m_strNumer = "";

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter05CaculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CChapter05CaculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChapter05CaculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter05CaculatorDlg::OnClickedButt9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(9);
}


void CChapter05CaculatorDlg::OnClickedButt8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(8);
}


void CChapter05CaculatorDlg::OnClickedButt7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(7);
}


void CChapter05CaculatorDlg::OnClickedButt6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(6);
}


void CChapter05CaculatorDlg::OnClickedButt5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(5);
}


void CChapter05CaculatorDlg::OnClickedButt4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(4);
}


void CChapter05CaculatorDlg::OnClickedButt3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(3);
}


void CChapter05CaculatorDlg::OnClickedButt2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(2);
}


void CChapter05CaculatorDlg::OnClickedButt1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(1);
}


void CChapter05CaculatorDlg::OnClickedButt0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Number(0);
}


void CChapter05CaculatorDlg::OnClickedButtAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Cal(1);
}

void CChapter05CaculatorDlg::OnClickedButtSub()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Cal(2);
}

void CChapter05CaculatorDlg::OnClickedButtMul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Cal(3);
}

void CChapter05CaculatorDlg::OnClickedButtDiv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Cal(4);
}

void CChapter05CaculatorDlg::OnClickedButtResult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	switch (m_iCal)
	{
	case 1:
		m_strLed.Format("%d", m_iOne + m_iTwo);
		break;
	case 2:
		m_strLed.Format("%d", m_iOne - m_iTwo);
		break;
	case 3:
		m_strLed.Format("%d", m_iOne * m_iTwo);
		break;
	case 4:
		m_strLed.Format("%d", m_iOne / m_iTwo);
		break;
	}

	m_iOne = atoi(m_strLed);

	UpdateData(FALSE);
}

void CChapter05CaculatorDlg::OnClickedButtZero()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_iCal = 0;
	m_iOne = 0;
	m_iTwo = 0;
	m_iSwitch = 0;
	m_strLed = "";
	m_strNumer = "";
	UpdateData(FALSE);
}


void CChapter05CaculatorDlg::Number(int a)
{
	// TODO: 여기에 구현 코드 추가.
	m_strNumer.Format("%d", a);

	m_strLed += m_strNumer;
	UpdateData(FALSE);
	
	if (m_iSwitch == 0)
	{
		m_iOne = atoi(m_strLed);
	}
	else {
		m_iTwo = atoi(m_strLed);
	}

}

void CChapter05CaculatorDlg::Cal(int a)
{
	// TODO: 여기에 구현 코드 추가.
	// 1 더하기
	// 2 빼기
	// 3 곱하기
	// 4 나누기

	m_iSwitch = 1;
	m_strLed = "";
	m_strNumer = "";
	m_iCal = a;
	UpdateData(FALSE);
}

void CChapter05CaculatorDlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}