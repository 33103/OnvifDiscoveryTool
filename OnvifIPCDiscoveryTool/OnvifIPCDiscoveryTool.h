// OnvifIPCDiscoveryTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// COnvifIPCDiscoveryToolApp:
// �йش����ʵ�֣������ OnvifIPCDiscoveryTool.cpp
//

class COnvifIPCDiscoveryToolApp : public CWinApp
{
public:
	COnvifIPCDiscoveryToolApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern COnvifIPCDiscoveryToolApp theApp;