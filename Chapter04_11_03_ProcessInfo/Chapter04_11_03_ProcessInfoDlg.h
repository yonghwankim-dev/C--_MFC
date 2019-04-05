
// Chapter04_11_03_ProcessInfoDlg.h: 헤더 파일
//

#pragma once


// CChapter041103ProcessInfoDlg 대화 상자
class CChapter041103ProcessInfoDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter041103ProcessInfoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER04_11_03_PROCESSINFO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	int m_ListValue;
	afx_msg void OnClickedButton2();
	afx_msg void OnClickedButton1();
//	CListCtrl m_ListValue;
//	int m_ListValue;
//	CListCtrl m_ListValue;
//	CListCtrl m_ListValue;
	int m_ListValue;
};
