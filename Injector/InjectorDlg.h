
// InjectorDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CInjectorDlg dialog
class CInjectorDlg : public CDialogEx
{
// Construction
public:
	CInjectorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INJECTOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};

DWORD GetProcessByName(const wchar_t *name);
char* ConvertString(wchar_t* string);
void* GetPayloadExportAddr(LPWSTR lpPath, HMODULE hPayloadBase, LPCSTR lpFunctionName);