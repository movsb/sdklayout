#ifndef __SDK_LAYOUT_H__
#define __SDK_LAYOUT_H__

#pragma once

#include <tchar.h>

#include "Utils.h"
#include "UIControl.h"
#include "UIContainer.h"
#include "UIManager.h"
#include "UIMarkup.h"
#include "UIDlgBuilder.h"
#include "UIVerticalLayout.h"
#include "UIHorizontalLayout.h"

namespace SdkLayout{

class CSdkLayout
{
public:
	CSdkLayout(){m_hWnd=NULL;m_pRoot=NULL;}
	~CSdkLayout(){DeleteLayout();}
	HWND GetHWND() const {return m_hWnd;}
	CContainerUI* GetRoot() const {return m_pRoot;}
	const SIZE& GetPostSize() const
	{
		assert(m_pRoot);
		assert(m_pRoot->GetAt(0));
		return m_pRoot->GetAt(0)->GetPostSize();
	}
	void ProcessScrollMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	CPaintManagerUI* GetManager() {return &m_Manager;}
	bool SetLayout(HWND hWnd, LPCTSTR xml, HINSTANCE hInst=NULL);
	bool SetLayout(HWND hWnd, UINT id, HINSTANCE hInst=NULL);
	void DeleteLayout();
	void ResizeLayout(const RECT& rc);
	void ResizeLayout();
	CControlUI* FindControl(LPCTSTR name);

private:
	void _InitializeLayout();
	void _ProcessScrollBar(const CDuiRect& rc);

private:
	HWND m_hWnd;
	CContainerUI* m_pRoot;
	CPaintManagerUI m_Manager;
	CDuiRect m_rcLast;
};

}
#endif // !__SDK_LAYOUT_H__
