#ifndef __UICONTAINER_H__
#define __UICONTAINER_H__

#pragma once

namespace SdkLayout {
/////////////////////////////////////////////////////////////////////////////////////
//

class CContainerUI : public CControlUI
{
public:
    CContainerUI();
    virtual ~CContainerUI();

public:
    int GetCount() const;
    bool Add(CControlUI* pControl);
    bool AddAt(CControlUI* pControl, int iIndex);
    bool Remove(CControlUI* pControl);
    bool RemoveAt(int iIndex);
    void RemoveAll();

    virtual void SetPos(const CDuiRect& rc);

	virtual void SetVisible(bool bVisible = true, bool bDispalyed = true);
	virtual void SetDisplayed(bool bDisplayed);

	virtual void SetHWND(HWND hWnd, CPaintManagerUI* mgr);
	virtual CControlUI* FindControl(LPCTSTR name);

protected:
    CStdPtrArray m_items;
    bool m_bScrollProcess; // ∑¿÷πSetPos—≠ª∑µ˜”√
};

} // namespace SdkLayout

#endif // __UICONTAINER_H__
