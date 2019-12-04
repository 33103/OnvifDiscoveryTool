// OnvifIPCDiscoveryToolDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OnvifIPCDiscoveryTool.h"
#include "OnvifIPCDiscoveryToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COnvifIPCDiscoveryToolDlg �Ի���

COnvifIPCDiscoveryToolDlg::COnvifIPCDiscoveryToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COnvifIPCDiscoveryToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COnvifIPCDiscoveryToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctlList1);
}

BEGIN_MESSAGE_MAP(COnvifIPCDiscoveryToolDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, &COnvifIPCDiscoveryToolDlg::OnButtonRefresh)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// COnvifIPCDiscoveryToolDlg ��Ϣ�������

BOOL COnvifIPCDiscoveryToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// Init WinSock
	WSADATA   data;
	int ret = WSAStartup(0x0202, &data);
	if (ret != 0)
	{
		WSACleanup();
		return FALSE;
	}

    m_ctlList1.SetExtendedStyle(/*LVS_EX_GRIDLINES|*/LVS_EX_FULLROWSELECT);

	m_ctlList1.InsertColumn(0,"IP��ַ", LVCFMT_LEFT, 150);
	m_ctlList1.InsertColumn(1,"���к�", LVCFMT_LEFT, 150);
    m_ctlList1.InsertColumn(2,"�豸����", LVCFMT_LEFT, 100);
	m_ctlList1.InsertColumn(3,"Ӳ���ͺ�", LVCFMT_LEFT, 100);
	m_ctlList1.InsertColumn(4,"�汾��Ϣ", LVCFMT_LEFT, 100);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void COnvifIPCDiscoveryToolDlg::OnDestroy()
{
	ClearOnlineListView();

	WSACleanup();

	CDialog::OnDestroy();

}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COnvifIPCDiscoveryToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR COnvifIPCDiscoveryToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CALLBACK OnvifDeviceDiscoverCB(DEVICE_IPC_INFO *pIpcInfo, LPVOID lpContext)
{
   if(pIpcInfo && lpContext)
   {
	  COnvifIPCDiscoveryToolDlg * pView = (COnvifIPCDiscoveryToolDlg*)lpContext;

	  pView->OnAddToList(pIpcInfo);
   }
}

void  COnvifIPCDiscoveryToolDlg::ClearOnlineListView()
{
	int nItemCount = m_ctlList1.GetItemCount();
	for(int i=0; i<nItemCount; i++)
	{
	   DEVICE_IPC_INFO * pIPCInfo = (DEVICE_IPC_INFO*)m_ctlList1.GetItemData(i);
	   if(pIPCInfo != NULL)
	   {
           delete pIPCInfo;
	   } 
	}
	m_ctlList1.DeleteAllItems();
}

void COnvifIPCDiscoveryToolDlg::OnButtonRefresh()
{
	 ClearOnlineListView();

	 m_OnvifDevicesSearcher.StopFind();

	 m_OnvifDevicesSearcher.SetDiscoveryInfoCB(OnvifDeviceDiscoverCB, this);
	 m_OnvifDevicesSearcher.StartFind();
}

void  COnvifIPCDiscoveryToolDlg::OnAddToList(DEVICE_IPC_INFO *pIPCInfo)
{
   	int nListItem = m_ctlList1.GetItemCount();
	m_ctlList1.InsertItem(nListItem, pIPCInfo->IP, -1);
	m_ctlList1.SetItemText(nListItem, 0, pIPCInfo->IP);
	m_ctlList1.SetItemText(nListItem, 1, pIPCInfo->DeviceID);
	m_ctlList1.SetItemText(nListItem, 2, "IPC");
	m_ctlList1.SetItemText(nListItem, 3, pIPCInfo->hardware_type);

	//DEVICE_IPC_INFO * pNewIpc = new DEVICE_IPC_INFO();

	m_ctlList1.SetItemData(nListItem, (DWORD_PTR)pIPCInfo);
}

