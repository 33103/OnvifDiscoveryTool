// OnvifIPCDiscoveryToolDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

#include "Discovery.h"

// COnvifIPCDiscoveryToolDlg �Ի���
class COnvifIPCDiscoveryToolDlg : public CDialog
{
// ����
public:
	COnvifIPCDiscoveryToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ONVIFIPCDISCOVERYTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	void  ClearOnlineListView();

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonRefresh();
    afx_msg void OnDestroy();

	afx_msg void OnButtonGetStreamUrl();
	afx_msg void OnButtonUserLoginInfo();

	DECLARE_MESSAGE_MAP()
public:
		
	void  OnAddToList(DEVICE_IPC_INFO *pIPCInfo);

	COnvifDiscovery   m_OnvifDevicesSearcher;
	CListCtrl m_ctlList1;
	

};
