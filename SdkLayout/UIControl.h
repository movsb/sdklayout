#ifndef __UICONTROL_H__
#define __UICONTROL_H__

#pragma once

namespace SdkLayout {

class CPaintManagerUI;

class CControlUI
{
public:
    CControlUI();
    virtual ~CControlUI();

    // 位置相关
    virtual const CDuiRect& GetPos() const;
    virtual void SetPos(const CDuiRect& rc);
    virtual int GetWidth() const;
    virtual int GetHeight() const;
    virtual int GetX() const;
    virtual int GetY() const;
    virtual SIZE GetFixedXY() const;         // 实际大小位置使用GetPos获取，这里得到的是预设的参考值
    virtual void SetFixedXY(SIZE szXY);      // 仅float为true时有效
    virtual int GetFixedWidth() const;       // 实际大小位置使用GetPos获取，这里得到的是预设的参考值
    virtual void SetFixedWidth(int cx);      // 预设的参考值
    virtual int GetFixedHeight() const;      // 实际大小位置使用GetPos获取，这里得到的是预设的参考值
    virtual void SetFixedHeight(int cy);     // 预设的参考值
    virtual int GetMinWidth() const;
    virtual void SetMinWidth(int cx);
    virtual int GetMaxWidth() const;
    virtual void SetMaxWidth(int cx);
    virtual int GetMinHeight() const;
    virtual void SetMinHeight(int cy);
    virtual int GetMaxHeight() const;
    virtual void SetMaxHeight(int cy);

    virtual bool IsVisible() const {return m_bVisible;}
	virtual void SetVisible(bool bVisible = true, bool bDispalyed = true) {m_bVisible = bVisible; SetDisplayed(bDispalyed);}
	virtual bool IsDispalyed() const {return m_bDisplayed;}
	virtual void SetDisplayed(bool bDisplayed) {m_bDisplayed = bDisplayed; ::ShowWindow(m_hWnd, bDisplayed?SW_SHOW:SW_HIDE);}

    virtual SIZE EstimateSize(SIZE szAvailable);
	virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

	virtual void SetInset(const CDuiRect& rc)	{m_rcInset = rc;}
	virtual const CDuiRect& GetInset() const	{return m_rcInset;}

	virtual void SetHWND(HWND hWnd, CPaintManagerUI* mgr) {m_hWnd = hWnd; m_pManager=mgr; SetFont(GetFont());	}
	virtual HWND GetHWND() const	{return m_hWnd;}

	virtual void SetID(int id) {m_id = id;}
	virtual int  GetID() const {return m_id;}

	virtual void SetFont(int id);
	virtual int  GetFont(){return m_font;}

	virtual void SetName(LPCTSTR name) {m_name = HashKey(name);};
	virtual UINT GetName() const {return m_name;}
	virtual CControlUI* FindControl(LPCTSTR name);

protected:
	HWND m_hWnd;
	int m_font;
	int  m_id;
	UINT m_name;

	CPaintManagerUI* m_pManager;
	CDuiRect m_rcInset;
    CDuiRect m_rcItem;
    SIZE m_cXY;
    SIZE m_cxyFixed;
    SIZE m_cxyMin;
    SIZE m_cxyMax;
    bool m_bVisible;
	bool m_bDisplayed;
    bool m_bSetPos; // 防止SetPos循环调用
};

} // namespace SdkLayout

#endif // __UICONTROL_H__
