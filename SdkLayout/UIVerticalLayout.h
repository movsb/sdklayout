#ifndef __UIVERTICALLAYOUT_H__
#define __UIVERTICALLAYOUT_H__

#pragma once

namespace SdkLayout
{
	class CVerticalLayoutUI : public CContainerUI
	{
	public:
		virtual void SetPos(const CDuiRect& rc);
	};
}
#endif // __UIVERTICALLAYOUT_H__
