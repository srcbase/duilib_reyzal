#include "stdafx.h"
#include "MainWnd.h"
#include "NewWnd.h"

DUI_BEGIN_MESSAGE_MAP(CMainWnd, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMSELECT, OnItemSelect)
DUI_END_MESSAGE_MAP()

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
	m_tabMain->SelectItem(0);
}

void CMainWnd::OnSelectChanged(TNotifyUI& msg)
{
	if (msg.pSender == m_optNormal)
	{
		m_tabMain->SelectItem(0);
	}
	else if (msg.pSender == m_optListview)
	{
		m_tabMain->SelectItem(1);
	}
	else if (msg.pSender == m_optTreeview)
	{
		m_tabMain->SelectItem(2);
	}
	else if (msg.pSender == m_optNormal1)
	{
		m_tabMain->SelectItem(3);
	}
	else if (msg.pSender == m_optNormal2)
	{
		m_tabMain->SelectItem(4);
	}
	else if (msg.pSender == m_optNormal3)
	{
		m_tabMain->SelectItem(5);
	}
	else if (msg.pSender == m_optTestRadio1 ||
		msg.pSender == m_optTestRadio2 ||
		msg.pSender == m_optTestRadio3 ||
		msg.pSender == m_optTestRadio4 ||
		msg.pSender == m_optTestRadio5
		)
	{
		ShowMessage(msg.pSender->GetText() + _T("ѡ��"));
	}
	else if (msg.pSender == m_chkTestCheck1 ||
		msg.pSender == m_chkTestCheck2 ||
		msg.pSender == m_chkTestCheck3 ||
		msg.pSender == m_chkTestCheck4 ||
		msg.pSender == m_chkTestCheck5
		)
	{
		ShowMessage(msg.pSender->GetText() + CDuiString((static_cast<CCheckBoxUI*>(msg.pSender))->IsSelected() ? _T("ѡ��") : _T("δѡ��")));
	}

}

void CMainWnd::OnClick(TNotifyUI& msg)
{
	if (msg.pSender == m_btnNormal ||
		msg.pSender == m_btnTooltip ||
		msg.pSender == m_btnFont
		)
	{
		ShowMessage(msg.pSender->GetText());
	}
	else if (msg.pSender == m_btnDisabled)
	{
		m_btnDisabled->SetEnabled(false);
		ShowMessage(msg.pSender->GetText());
	}
	else if (msg.pSender == m_btnWindowNormal)
	{
		CNewWnd* pNewWnd = new CNewWnd();
		pNewWnd->Create(m_hWnd, _T(""), UI_WNDSTYLE_DIALOG, UI_WNDSTYLE_EX_DIALOG);
		pNewWnd->CenterWindow();
		pNewWnd->ShowWindow();
	}
	else if (msg.pSender == m_btnWindowDomodal)
	{
		CNewWnd* pNewWnd = new CNewWnd();
		pNewWnd->Create(m_hWnd, _T(""), UI_WNDSTYLE_DIALOG, UI_WNDSTYLE_EX_DIALOG);
		pNewWnd->CenterWindow();
		pNewWnd->ShowModal();
	}
	return WindowImplBase::OnClick(msg);
}

void CMainWnd::OnItemSelect(TNotifyUI& msg)
{
	if (msg.pSender == m_comNormal)
	{
		int index = m_comNormal->GetCurSel();
		if (index >= 0 && index < m_comNormal->GetCount()) {
			ShowMessage(m_comNormal->GetItemAt(index)->GetText());
		}
	}
}

void CMainWnd::ShowMessage(LPCTSTR strMsg)
{
	MessageBox(NULL, strMsg, _T("��ʾ"), MB_OK);
}

//��ʼ���ؼ�
bool CMainWnd::InitControl(void)
{
	
	//tab��
	m_optNormal = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_normal")));
	m_optListview = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_listview")));
	m_optTreeview = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_treeview")));
	m_optNormal1 = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_normal1")));
	m_optNormal2 = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_normal2")));
	m_optNormal3 = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_normal3")));

	m_tabMain = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tab_main")));

	//��ť
	m_btnNormal = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_normal")));
	m_btnDisabled = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_disabled")));
	m_btnTooltip = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_tooltip")));
	m_btnFont = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_font")));

	//ѡ���
	m_chkTestCheck1 = static_cast<CCheckBoxUI*>(m_PaintManager.FindControl(_T("chk_test_check1")));
	m_chkTestCheck2 = static_cast<CCheckBoxUI*>(m_PaintManager.FindControl(_T("chk_test_check2")));
	m_chkTestCheck3 = static_cast<CCheckBoxUI*>(m_PaintManager.FindControl(_T("chk_test_check3")));
	m_chkTestCheck4 = static_cast<CCheckBoxUI*>(m_PaintManager.FindControl(_T("chk_test_check4")));
	m_chkTestCheck5 = static_cast<CCheckBoxUI*>(m_PaintManager.FindControl(_T("chk_test_check5")));

	//��ѡ
	m_optTestRadio1 = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_test_radio1")));
	m_optTestRadio2 = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_test_radio2")));
	m_optTestRadio3 = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_test_radio3")));
	m_optTestRadio4 = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_test_radio4")));
	m_optTestRadio5 = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_test_radio5")));

	//combo
	m_comNormal = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("com_normal")));

	//���ڵ�������
	m_btnWindowNormal = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_window_normal")));
	m_btnWindowDomodal = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_window_domodal")));

	assert(
		m_optNormal&&
		m_optListview&&
		m_optTreeview&&
		m_optNormal1&&
		m_optNormal2&&
		m_optNormal3&&
		m_tabMain&&
		m_btnNormal&&
		m_btnDisabled&&
		m_btnTooltip&&
		m_btnFont&&
		m_chkTestCheck1&&
		m_chkTestCheck2&&
		m_chkTestCheck3&&
		m_chkTestCheck4&&
		m_chkTestCheck5&&
		m_optTestRadio1&&
		m_optTestRadio2&&
		m_optTestRadio3&&
		m_optTestRadio4&&
		m_optTestRadio5&&
		m_comNormal&&
		m_btnWindowNormal&&
		m_btnWindowDomodal
	);
	return true;
}
