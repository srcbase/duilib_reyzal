#include "stdafx.h"
#include "NewWnd.h"


CNewWnd::CNewWnd() {
}


CNewWnd::~CNewWnd() {
}

//������Ϣ�ӹܺ���
LRESULT CNewWnd::HandleMessage(UINT uMsg,
                               WPARAM wParam,
                               LPARAM lParam) {
    return WindowImplBase::HandleMessage(uMsg, wParam, lParam);
}
//������Ϣ��Ӧ����
void CNewWnd::Notify(TNotifyUI& msg) {
    return WindowImplBase::Notify(msg);
}

void CNewWnd::InitWindow() {
    InitControl();
}

//��ʼ���ؼ�
bool CNewWnd::InitControl(void) {
    m_labCaption = static_cast<CLabelUI*>(m_pm.FindControl(_T("lab_caption")));
    assert(m_labCaption);
    return true;
}
