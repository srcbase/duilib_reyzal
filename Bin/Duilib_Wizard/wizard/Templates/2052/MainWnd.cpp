#include "stdafx.h"
#include "MainWnd.h"
//������Ϣ�ӹܺ���
LRESULT CMainWnd::HandleMessage(UINT uMsg, 
									   WPARAM wParam,
									   LPARAM lParam)
{
	return WindowImplBase::HandleMessage(uMsg,wParam,lParam);
}
//������Ϣ��Ӧ����
void CMainWnd::Notify(TNotifyUI& msg)
{
	return WindowImplBase::Notify(msg);
}
void CMainWnd::InitWindow()
{
	InitControl();
	labCaption->SetText(APP_NAME);
}


//��ʼ���ؼ�
bool CMainWnd::InitControl(void)
{
	labCaption = (CLabelUI*)m_PaintManager.FindControl(_T("caption"));//����
	return false;
}
