#pragma once


// CDeviceUserLoginInfo �Ի���

class CDeviceUserLoginInfo : public CDialog
{
	DECLARE_DYNAMIC(CDeviceUserLoginInfo)

public:
	CDeviceUserLoginInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeviceUserLoginInfo();

// �Ի�������
	enum { IDD = IDD_DIALOG_DEVICE_AUTH_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

public:

   CString   m_strUserName;
   CString   m_strPassword;
};
