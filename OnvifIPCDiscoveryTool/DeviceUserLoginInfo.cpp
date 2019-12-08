// DeviceUserLoginInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OnvifIPCDiscoveryTool.h"
#include "DeviceUserLoginInfo.h"


// CDeviceUserLoginInfo �Ի���

IMPLEMENT_DYNAMIC(CDeviceUserLoginInfo, CDialog)

CDeviceUserLoginInfo::CDeviceUserLoginInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDeviceUserLoginInfo::IDD, pParent)
{

}

CDeviceUserLoginInfo::~CDeviceUserLoginInfo()
{
}

void CDeviceUserLoginInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeviceUserLoginInfo, CDialog)
	ON_BN_CLICKED(IDOK, &CDeviceUserLoginInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// CDeviceUserLoginInfo ��Ϣ�������
BOOL CDeviceUserLoginInfo::OnInitDialog()
{
	CDialog::OnInitDialog();

	GetDlgItem(IDC_EDIT_USERNAME)->SetWindowText(m_strUserName);
	GetDlgItem(IDC_EDIT_PASSWORD)->SetWindowText(m_strPassword);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDeviceUserLoginInfo::OnBnClickedOk()
{
	CString strUserName, strPassword;
	GetDlgItem(IDC_EDIT_USERNAME)->GetWindowText(strUserName);
    GetDlgItem(IDC_EDIT_PASSWORD)->GetWindowText(strPassword);
	if(strUserName.IsEmpty() || strPassword.IsEmpty())
	{
		MessageBox(_T("�û��������벻��Ϊ��"), _T("��ʾ"), MB_OK|MB_ICONWARNING);
		return;
	}
	m_strUserName = strUserName;
	m_strPassword = strPassword;


	OnOK();
}


