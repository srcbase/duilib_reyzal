#pragma once

#define APP_NAME _T("DuilibDemo")


class CMainWnd : public WindowImplBase
{
public:
	//tab栏
	COptionUI* m_optNormal;
	COptionUI* m_optListview;
	COptionUI* m_optTreeview;
	COptionUI* m_optNormal1;
	COptionUI* m_optNormal2;
	COptionUI* m_optNormal3;
	//切换
	CTabLayoutUI* m_tabMain;
	//按钮
	CButtonUI* m_btnNormal;
	CButtonUI* m_btnDisabled;
	CButtonUI* m_btnTooltip;
	CButtonUI* m_btnFont;

	//选择框
	CCheckBoxUI* m_chkTestCheck1;
	CCheckBoxUI* m_chkTestCheck2;
	CCheckBoxUI* m_chkTestCheck3;
	CCheckBoxUI* m_chkTestCheck4;
	CCheckBoxUI* m_chkTestCheck5;

	//单选
	COptionUI* m_optTestRadio1;
	COptionUI* m_optTestRadio2;
	COptionUI* m_optTestRadio3;
	COptionUI* m_optTestRadio4;
	COptionUI* m_optTestRadio5;

	//combo
	CComboUI* m_comNormal;

	CButtonUI* m_btnWindowNormal;
	CButtonUI* m_btnWindowDomodal;


	DUI_DECLARE_MESSAGE_MAP()

public:
	CMainWnd(){};
	virtual LRESULT		HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual LPCTSTR		GetWindowClassName() const   {   return _T("DuilibClass");  }
	virtual CDuiString	GetSkinFile()                {   return _T("MainWnd.xml");  }
	virtual LPCTSTR GetResourceID() const {return  MAKEINTRESOURCE(IDR_ZIPRES1);}
	virtual UILIB_RESOURCETYPE GetResourceType() const  {return UILIB_ZIPRESOURCE;}; 
	virtual CDuiString GetSkinFolder()              {   return _T("");  }
 	void OnFinalMessage(HWND /*hWnd*/) { };
	virtual void InitWindow();
	void OnSelectChanged(TNotifyUI & msg);
	virtual void OnClick(TNotifyUI & msg) override;
	void OnItemSelect(TNotifyUI & msg);
	void ShowMessage(LPCTSTR strMsg);
 	void Notify(TNotifyUI& msg);
private:
	//初始化控件
	bool InitControl(void);
};
