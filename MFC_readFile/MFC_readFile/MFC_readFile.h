// MFC_readFile.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_readFileApp:
// �йش����ʵ�֣������ MFC_readFile.cpp
//

class CMFC_readFileApp : public CWinApp
{
public:
	CMFC_readFileApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_readFileApp theApp;