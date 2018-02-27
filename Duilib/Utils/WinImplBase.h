/**
 * @file WinImplBase.h
 * @bref ͨ�ô�����
 * @details
 */
#ifndef WIN_IMPL_BASE_HPP
#define WIN_IMPL_BASE_HPP

namespace DuiLib {
/**
 * @bref ���ص���Դ����
 * @details
 */
enum UILIB_RESOURCETYPE {
    UILIB_FILE = 1,			/**< ���Դ����ļ� */
    UILIB_ZIP,				/**< ���Դ���zipѹ���� */
    UILIB_RESOURCE,			/**< ������Դ */
    UILIB_ZIPRESOURCE,		/**< ������Դ��zipѹ���� */
};

/**
 * @bref ��װ�õ�һ��ͨ�ô�����
 * @details ���ദ���˴󲿷�Ĭ����Ϣ,��������ʱֻ��Ҫ�̳б��༴��
 */
class DUILIB_API WindowImplBase
    : public CWindowWnd
    , public CNotifyPump
    , public INotifyUI
    , public IMessageFilterUI
    , public IDialogBuilderCallback {
public:
    WindowImplBase() {};
    virtual ~WindowImplBase() {};
    /**
     * @bref ��ʼ��������ɺ����
     * @details
     * @return ��
     */
    virtual void InitWindow() {};

    /**
    * @bref ���ڹر�֮�����
    * @details
    * @param hWnd ��ǰ���ھ��
    * @return ��
    */
    virtual void OnFinalMessage(HWND hWnd);

    /**
    * @bref ����duilib�е���Ϣ
    * @details
    * @param msg��һ��TNotifyUI�ṹ��������ǰ��Ϣ������
    * @return ��
    */
    virtual void Notify(TNotifyUI& msg);

    DUI_DECLARE_MESSAGE_MAP()

    /**
    * @bref ����duilib�е�click�¼�
    * @details
    * @param msg��һ��TNotifyUI�ṹ��������ǰ��Ϣ������
    */
    virtual void OnClick(TNotifyUI& msg);

protected:
    /**
    * @bref ��ȡ����Ƥ������·��
    * @return ����Ƥ������·��
    */
    virtual CDuiString GetSkinFolder() = 0;

    /**
    * @bref ��ȡ����Ƥ���ļ���
    * @return ����Ƥ���ļ���
    */
    virtual CDuiString GetSkinFile() = 0;
    /**
    * @bref ��ȡ��ǰ��������
    * @return ��ǰ��������
    */
    virtual LPCTSTR GetWindowClassName(void) const = 0;
    /**
    * @bref ����ESE����Enter����WM_KEYDOWN��Ϣ
    * @param wParam��ʾ��ǰ���¼���VK��
    * @return
    */
    virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam);

    static LPBYTE m_lpResourceZIPBuffer;
    CPaintManagerUI m_pm;

public:
    virtual UINT GetClassStyle() const;
    virtual UILIB_RESOURCETYPE GetResourceType() const;
    virtual CDuiString GetZIPFileName() const;
    virtual LPCTSTR GetResourceID() const;
    virtual CControlUI* CreateControl(LPCTSTR pstrClass);
    virtual LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM /*lParam*/, bool& /*bHandled*/);
    virtual LRESULT OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
    virtual LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);

#if defined(WIN32) && !defined(UNDER_CE)
    virtual LRESULT OnNcActivate(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL& bHandled);
    virtual LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    virtual LRESULT OnNcPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
    virtual LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    virtual LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    virtual LRESULT OnMouseWheel(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
    virtual LRESULT OnMouseHover(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
#endif
    virtual LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    virtual LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    virtual LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    virtual LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    virtual LRESULT OnKeyDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
    virtual LRESULT OnKillFocus(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
    virtual LRESULT OnSetFocus(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
    virtual LRESULT OnLButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
    virtual LRESULT OnLButtonUp(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
    virtual LRESULT OnMouseMove(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
    virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    virtual LONG GetStyle();
};
}

#endif // WIN_IMPL_BASE_HPP
