#ifndef __UIHORIZONTALLAYOUT_H__
#define __UIHORIZONTALLAYOUT_H__

#pragma once

namespace SdkLayout
{
	class  CHorizontalLayoutUI : public CContainerUI
	{
	public:
		virtual void SetPos(const CDuiRect& rc);
	};
}
#endif // __UIHORIZONTALLAYOUT_H__
