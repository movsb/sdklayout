#ifndef __SDK_LAYOUT_H__
#define __SDK_LAYOUT_H__

#pragma once

namespace SdkLayout{

class CSdkLayout
{
public:
	CSdkLayout(){m_hWnd=NULL;m_pRoot=NULL;}
	~CSdkLayout(){DeleteLayout();}
	HWND GetHWND() const {return m_hWnd;}
	CContainerUI* GetRoot() const {return m_pRoot;}
	CPaintManagerUI* GetManager() {return &m_Manager;}
	bool SetLayout(HWND hWnd, LPCTSTR xml, HINSTANCE hInst=NULL);
	void DeleteLayout();
	void ResizeLayout(const RECT& rc);
	CControlUI* FindControl(LPCTSTR name);
	bool VisibleControl(CControlUI* pControl, bool bVisible, bool bDisplayed);
	bool VisibleControl(LPCTSTR name, bool bVisible, bool bDisplayed);


private:
	HWND m_hWnd;
	CContainerUI* m_pRoot;
	CPaintManagerUI m_Manager;

};

}
#endif // !__SDK_LAYOUT_H__
