#pragma once

#include  "OnvifClientLib.h"
#include "afxwin.h"
#pragma comment(lib, "OnvifClientLib.lib")

#include "ColorStatic.h"
#include "Discovery.h"

// CGetStreamURLDlg �Ի���

class CGetStreamURLDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetStreamURLDlg)

public:
	CGetStreamURLDlg(CWnd* pParent, DEVICE_IPC_INFO * pIpcInfo);   // ��׼���캯��
	virtual ~CGetStreamURLDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_RTSP_URL_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	
    afx_msg void OnCbnSelchangeComboStreamIndex();
	LRESULT OnStreamInfoNotifyMSg(WPARAM wParam, LPARAM lParam);

	void RequestStreamInfo();

protected:
	HANDLE  m_hOnvifRequestThread;

	CColorStatic m_responseStatus; //����Onvif�Ļظ�״̬��Ϣ

	static DWORD WINAPI OnvifThrd(void * pParam);
	int OnvifThreadProc();

public:
   MediaProfile   m_mediaProfile;

   DEVICE_IPC_INFO * m_pIPCInfo;
   

};
