#include "StdAfx.h"

namespace SdkLayout
{
	CContainerUI::CContainerUI()
		: m_bScrollProcess(false)
	{

	}

	CContainerUI::~CContainerUI()
	{
		RemoveAll();
	}

	int CContainerUI::GetCount() const
	{
		return m_items.GetSize();
	}

	bool CContainerUI::Add(CControlUI* pControl)
	{
		if( pControl == NULL) return false;
		return m_items.Add(pControl);   
	}

	bool CContainerUI::Remove(CControlUI* pControl)
	{
		if( pControl == NULL) return false;

		for( int it = 0; it < m_items.GetSize(); it++ ) {
			if( static_cast<CControlUI*>(m_items[it]) == pControl ) {
				return m_items.Remove(it);
			}
		}
		return false;
	}

	void CContainerUI::RemoveAll()
	{
		for(int c=m_items.GetSize(), i=0; i<c; ++i){
			delete static_cast<CControlUI*>(m_items[i]);
		}
		m_items.Empty();
	}

	void CContainerUI::SetPos(const CDuiRect& rc)
	{
		m_rcItem = rc;
		if(m_rcItem.right < m_rcItem.left) m_rcItem.right  = m_rcItem.left;
		if(m_rcItem.bottom< m_rcItem.top)  m_rcItem.bottom = m_rcItem.top;

		if( m_items.IsEmpty() ) return;

		CDuiRect rct = m_rcItem;
		rct.left   += m_rcInset.left;
		rct.top    += m_rcInset.top;
		rct.right  -= m_rcInset.right;
		rct.bottom -= m_rcInset.bottom;

		for( int it = 0; it < m_items.GetSize(); it++ ) {
			CControlUI* pControl = static_cast<CControlUI*>(m_items[it]);
			if( !pControl->IsVisible() ) continue;
			pControl->SetPos(rct); // 所有非float子控件放大到整个客户区
		}
	}

	void CContainerUI::SetHWND(HWND hWnd, CPaintManagerUI* mgr)
	{
		for(int c = GetCount(), i=0; i<c; ++i){
			CControlUI* pControl = static_cast<CControlUI*>(m_items[i]);
			
			HWND hChild = NULL;
			// 这里所谓的 "容器" 只是一个虚拟的窗口, 它本身并不具有窗口句柄
			if(typeid(*pControl) == typeid(CControlUI)){
				int id = pControl->GetID();
				if(id == -1)
					hChild = NULL;
				else
					hChild = GetDlgItem(hWnd, pControl->GetID());
			}
			else{
				hChild = hWnd;
			}
			pControl->SetHWND(hChild, mgr);
		}
	}

	CControlUI* CContainerUI::FindControl(LPCTSTR name)
	{
		UINT hash = HashKey(name);
		if(hash == m_name) return static_cast<CControlUI*>(this);
		else{
			for(int i=0; i<m_items.GetSize(); i++){
				CControlUI* pControl = static_cast<CControlUI*>(m_items[i]);
				CControlUI* pSubControl = NULL;
				pSubControl = pControl->FindControl(name);
				if(pSubControl)
					return pSubControl;
			}
		}
		return NULL;
	}

	void CContainerUI::SetVisible( bool bVisible /*= true*/, bool bDispalyed /*= true*/ )
	{
		m_bVisible = bVisible;
		for(int i=0; i<m_items.GetSize(); i++){
			CControlUI* pControl = static_cast<CControlUI*>(m_items[i]);
			pControl->SetVisible(bVisible,bVisible);
			pControl->SetDisplayed(bDispalyed);
		}
	}

	void CContainerUI::SetDisplayed( bool bDisplayed )
	{
		m_bDisplayed = bDisplayed;
		::ShowWindow(GetHWND(),m_bDisplayed?SW_SHOW:SW_HIDE);
	}

} // namespace SdkLayout
