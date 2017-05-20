
// Injector.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CInjectorApp:
// See Injector.cpp for the implementation of this class
//

class CInjectorApp : public CWinApp
{
public:
	CInjectorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CInjectorApp theApp;