
// InjectorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Injector.h"
#include "InjectorDlg.h"
#include "afxdialogex.h"
#include <tlhelp32.h>
#include <PathCch.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HMODULE openFF8 = NULL;
wchar_t dll[MAX_PATH];
// CInjectorDlg dialog

CInjectorDlg::CInjectorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INJECTOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInjectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CInjectorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CInjectorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CInjectorDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CInjectorDlg message handlers

BOOL CInjectorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CInjectorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CInjectorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CInjectorDlg::OnBnClickedOk()
{
	char* dllChar;
	wchar_t exeName[MAX_PATH];
	GetModuleFileName(NULL, dll, 256);
	PathCchRemoveFileSpec(dll, 256);
	PathCchAppendEx(dll, 256, L"OpenFF8.dll", 0);
	dllChar = ConvertString(dll);
	GetDlgItemText(IDC_EXE, exeName, 16);
	DWORD procid = GetProcessByName(exeName);
	HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procid);
	LPVOID addr = GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryA");
	LPVOID arg = VirtualAllocEx(process, NULL, strlen(dllChar) + 1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	int n = WriteProcessMemory(process, arg, dllChar, strlen(dllChar) + 1, NULL);
	HANDLE threadID = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)addr, arg, NULL, NULL);
	WaitForSingleObject(threadID, INFINITE);
	GetExitCodeThread(threadID, (LPDWORD)&openFF8);
	delete[] dllChar;
	VirtualFreeEx(process, arg, 0, MEM_RELEASE);
	CloseHandle(process);
}


void CInjectorDlg::OnBnClickedCancel()
{
	wchar_t exeName[MAX_PATH];
	GetDlgItemText(IDC_EXE, exeName, 16);
	DWORD procid = GetProcessByName(exeName);
	HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procid);
	LPVOID addr = GetPayloadExportAddr(dll, openFF8, "UnloadDll");
	HANDLE threadID = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)addr, NULL, NULL, NULL);
	WaitForSingleObject(threadID, INFINITE);
	CloseHandle(process);
}

DWORD GetProcessByName(const wchar_t *name)
{
	PROCESSENTRY32 pt;

	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pt.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(hsnap, &pt))
	{
		do
		{
			if (!lstrcmpi(pt.szExeFile, name))
			{
				CloseHandle(hsnap);
				return pt.th32ProcessID;
			}
		} while (Process32Next(hsnap, &pt));
	}
	CloseHandle(hsnap);
	return 0;
}

void* GetPayloadExportAddr(LPWSTR lpPath, HMODULE hPayloadBase, LPCSTR lpFunctionName) {
	// Load payload in our own virtual address space
	HMODULE hLoaded = LoadLibrary(lpPath);

	if (hLoaded == NULL) {
		return NULL;
	}
	else {
		void* lpFunc = GetProcAddress(hLoaded, lpFunctionName);
		DWORD dwOffset = (char*)lpFunc - (char*)hLoaded;

		FreeLibrary(hLoaded);
		return (void*)((DWORD)hPayloadBase + dwOffset);
	}
}

char* ConvertString(wchar_t* string) {
	// Convert the wchar_t string to a char* string. Record   
	//.the length of the original string and add 1 to it to  
	//.account for the terminating null character.  
	size_t origsize = wcslen(string) + 1;

	// Allocate two bytes in the multibyte output string for every wide  
	// character in the input string (including a wide character  
	// null). Because a multibyte character can be one or two bytes,  
	// you should allot two bytes for each character. Having extra  
	// space for the new string is not an error, but having  
	// insufficient space is a potential security problem.  
	const size_t newsize = origsize * 2;
	// The new string will contain a converted copy of the original  
	// string plus the type of string appended to it.  
	char *nstring = new char[newsize];

	// Put a copy of the converted string into nstring  
	wcstombs_s(NULL, nstring, newsize, string, _TRUNCATE);
	// Display the result.  
	return nstring;
}