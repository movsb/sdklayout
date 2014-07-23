#ifndef __UICONTROL_H__
#define __UICONTROL_H__

#pragma once

namespace SdkLayout {

class CPaintManagerUI;
class CContainerUI;
class CHorizontalLayoutUI;
class CVerticalLayoutUI;

class CControlUI
{
public:
    CControlUI();
    virtual ~CControlUI();

	virtual LPCTSTR GetClass() const {return GetClassStatic();}
	static LPCTSTR GetClassStatic() {return _T("Control");}

	virtual void DoInit();

	virtual bool SetFocus();

    // 位置相关
    virtual const CDuiRect& GetPos() const;
    virtual void SetPos(const CDuiRect& rc);
	virtual void SetPostSize(const SIZE& sz) {m_szPostSize = sz;}
	virtual const SIZE& GetPostSize() const {return m_szPostSize;}
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
	virtual void SetVisible(bool bVisible = true, bool bDispalyed = true) 
	{
		m_bVisible = bVisible; 
		SetDisplayed(bDispalyed);
		NeedParentUpdate();
	}
	virtual void SetVisibleByParent(bool bVisible, bool bDisplayed)
	{
		if(bVisible && bDisplayed){
			// 如果父容器设置为可见, 则根据当前控件实际情况来设置
			SetVisible(IsVisible(), IsDispalyed());
		}
		else{
			// 如果父容器设置为不可见, 则隐藏当前控件
			// 但不应该更改控件实际的隐藏情况
			bool bOldVisible = IsVisible();
			bool bOldDisplayed = IsDispalyed();
			SetVisible(false, false);
			m_bVisible = bOldVisible;
			m_bDisplayed = bOldDisplayed;
		}
	}

	virtual bool IsDispalyed() const {return m_bDisplayed;}
	virtual void SetDisplayed(bool bDisplayed) 
	{
		if(IsVisible()){
			::ShowWindow(m_hWnd, bDisplayed?SW_SHOW:SW_HIDE);
			m_bDisplayed = bDisplayed;
		}
		else{ // 如果隐藏了控件, 则显示设置无效
			::ShowWindow(m_hWnd, SW_HIDE);
			bDisplayed = false;
		}
	}

    virtual SIZE EstimateSize(SIZE szAvailable);
	virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

	virtual void SetInset(const CDuiRect& rc)	{m_rcInset = rc;}
	virtual const CDuiRect& GetInset() const	{return m_rcInset;}

	virtual void SetHWND(HWND hWnd, CPaintManagerUI* mgr)
	{
		m_hWnd = hWnd; 
		m_pManager=mgr; 
	}

	virtual HWND GetHWND() const	{return m_hWnd;}

	virtual void NeedUpdate()
	{
		SetPos(GetPos());
	}
	virtual void NeedParentUpdate()
	{
		if(GetParent())
			GetParent()->NeedUpdate();
		else
			NeedUpdate(); // root only
	}
	virtual void SetID(int id) {m_id = id;}
	virtual int  GetID() const {return m_id;}

	virtual void SetFont(int id);
	virtual int  GetFont(){return m_font;}

	virtual CControlUI* GetParent() const {return m_pParent;}
	virtual void SetParent(CControlUI* pParent) { assert(pParent); m_pParent = pParent;}

	virtual void SetName(LPCTSTR name) {m_name = HashKey(name);};
	virtual UINT GetName() const {return m_name;}
	virtual CControlUI* FindControl(LPCTSTR name);

	CContainerUI* ToContainerUI() {return (CContainerUI*)(this);}
	CHorizontalLayoutUI* ToHorizontalUI() {return (CHorizontalLayoutUI*)(this);}
	CVerticalLayoutUI* ToVerticalUI() {return (CVerticalLayoutUI*)(this);}

protected:
	HWND m_hWnd;
	int m_font;
	int  m_id;
	UINT m_name;

	CPaintManagerUI* m_pManager;
	CControlUI* m_pParent; // should be CContainerUI*
	CDuiRect m_rcInset;
    CDuiRect m_rcItem;
    SIZE m_cXY;
    SIZE m_cxyFixed;
    SIZE m_cxyMin;
    SIZE m_cxyMax;
	SIZE m_szPostSize;
    bool m_bVisible;
	bool m_bVisibleByParent;
	bool m_bDisplayed;
};

} // namespace SdkLayout

#endif // __UICONTROL_H__
