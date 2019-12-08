
#pragma once

struct  MediaProfile
{
	int  count;
	char stream_uri[3][256];
	char profile_name[3][32];
};

#ifdef __cplusplus
extern"C"{
#endif

#ifdef		ONVIFCLIENTLIB_EXPORTS	
#define		ONVIFDLL_API	__declspec(dllexport)
#else
#define		ONVIFDLL_API	__declspec(dllimport)
#endif

//�������ã� �������
//����ֵ��  ʼ�շ���0
ONVIFDLL_API int SetDeviceHost(char * szDeviceIP, int port, char * user, char * pass);

//�������ã�  ��ȡ�豸��Ϣ
//����ֵ��0���ɹ��� -1�����ӳɹ�������ȡ��Ϣʧ�ܣ� -2�����ӷ�����ʧ�ܣ������豸������
ONVIFDLL_API int GetStreamInfo(MediaProfile * pProfile);

#ifdef __cplusplus
}
#endif