#pragma once



extern CString   UIntToString(UINT value);
extern INT       StringToInt(CString & str);
extern CString   IntToString(INT value);
extern  INT      HexToInt(const char * szHex, int len);
extern  CString  RectToString(RECT & rc);
extern  BOOL     StringToRect(CString str, RECT &rc);
extern CString   GetAppDir();

//��ȡһ�������UUID�ַ���
extern CString  CreateUuid();

//��ȡ�ַ�����ʽ��IP�������dwIP����Ϊ�����ֽ���
extern CString  ToIPStr(DWORD dwIP);

//���������HTTP URL�����IP���˿ڡ���Դ·��
extern int HttpUrlGetIpPort(char *pUrl, char *pIp, USHORT *pPort, char *pName);

//���������RTSP URL�����IP���˿ڡ�������
extern int RtspUrlGetIpPort(char *pUrl, char *pIp, USHORT *pPort, char *pName);

extern BOOL StringToCTime(const char * szTime, CTime & t);
extern CString CTimeToString(CTime & t);


extern CString  SecondsToTimeStr(int nSec);
