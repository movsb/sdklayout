#if !defined(AFX_STDAFX_H__E30B2003_188B_4EB4_AB99_3F3734D6CE6C__INCLUDED_)
#define AFX_STDAFX_H__E30B2003_188B_4EB4_AB99_3F3734D6CE6C__INCLUDED_

#pragma once

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <typeinfo>
#include <windows.h>
#include <windowsx.h>
#include <olectl.h>
#include <tchar.h>
#include <cassert>

#include "Utils.h"
#include "UIControl.h"
#include "UIContainer.h"
#include "UIManager.h"
#include "UIMarkup.h"
#include "UIDlgBuilder.h"
#include "UIVerticalLayout.h"
#include "UIHorizontalLayout.h"

#include "SdkLayout.h"

#define lengthof(x) (sizeof(x)/sizeof(*x))
#define MAX max
#define MIN min
#define CLAMP(x,a,b) (MIN(b,MAX(a,x)))

#endif // !defined(AFX_STDAFX_H__E30B2003_188B_4EB4_AB99_3F3734D6CE6C__INCLUDED_)
