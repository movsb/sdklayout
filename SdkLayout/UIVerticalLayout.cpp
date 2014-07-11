#include "stdafx.h"
#include "UIVerticalLayout.h"

namespace SdkLayout
{
	void CVerticalLayoutUI::SetPos(const CDuiRect& rc)
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

		// Determine the width of elements that are sizeable
		SIZE szAvailable = {rct.GetWidth(), rct.GetHeight()};
		int nAdjustables = 0;
		int cyFixed = 0;
		int nEstimateNum = 0;
		for( int it1 = 0; it1 < m_items.GetSize(); it1++ ) {
			CControlUI* pControl = static_cast<CControlUI*>(m_items[it1]);
			if( !pControl->IsVisible() ) continue;
			SIZE sz = pControl->EstimateSize(szAvailable);
			if( sz.cy == 0 ) {
				nAdjustables++;
			}
			else {
				if( sz.cy < pControl->GetMinHeight() ) sz.cy = pControl->GetMinHeight();
				if( sz.cy > pControl->GetMaxHeight() ) sz.cy = pControl->GetMaxHeight();
			}
			cyFixed += sz.cy;
			nEstimateNum++;
		}

		// Place elements
		int cyNeeded = 0;
		int cyExpand = 0;
		if( nAdjustables > 0 ) cyExpand = MAX(0, (szAvailable.cy - cyFixed) / nAdjustables);
		// Position the elements
		SIZE szRemaining = szAvailable;
		int iPosY = rct.top;
		int iPosX = rct.left;
		int iAdjustable = 0;
		int cyFixedRemaining = cyFixed;
		for( int it2 = 0; it2 < m_items.GetSize(); it2++ ) {
			CControlUI* pControl = static_cast<CControlUI*>(m_items[it2]);
			if( !pControl->IsVisible() ) continue;

			SIZE sz = pControl->EstimateSize(szRemaining);
			if( sz.cy == 0 ) {
				iAdjustable++;
				sz.cy = cyExpand;
				// Distribute remaining to last element (usually round-off left-overs)
				if( iAdjustable == nAdjustables ) {
					sz.cy = MAX(0, szRemaining.cy - cyFixedRemaining);
				} 
				if( sz.cy < pControl->GetMinHeight() ) sz.cy = pControl->GetMinHeight();
				if( sz.cy > pControl->GetMaxHeight() ) sz.cy = pControl->GetMaxHeight();
			}
			else {
				if( sz.cy < pControl->GetMinHeight() ) sz.cy = pControl->GetMinHeight();
				if( sz.cy > pControl->GetMaxHeight() ) sz.cy = pControl->GetMaxHeight();
				cyFixedRemaining -= sz.cy;
			}

			sz.cx = pControl->GetFixedWidth();
			if( sz.cx == 0 ) sz.cx = szAvailable.cx;
			if( sz.cx < 0 ) sz.cx = 0;
			if( sz.cx < pControl->GetMinWidth() ) sz.cx = pControl->GetMinWidth();
			if( sz.cx > pControl->GetMaxWidth() ) sz.cx = pControl->GetMaxWidth();

			RECT rcCtrl = { iPosX, iPosY, iPosX + sz.cx, iPosY + sz.cy};
			pControl->SetPos(rcCtrl);

			iPosY += sz.cy;
			cyNeeded += sz.cy ;
			szRemaining.cy -= sz.cy;
		}
	}
}
