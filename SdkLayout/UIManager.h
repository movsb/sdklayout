#ifndef __UIMANAGER_H__
#define __UIMANAGER_H__

#pragma once

namespace SdkLayout {
/////////////////////////////////////////////////////////////////////////////////////
//

class CControlUI;

class CPaintManagerUI
{
public:
    CPaintManagerUI();
    ~CPaintManagerUI();

public:
    HFONT GetDefaultFont();
    void SetDefaultFont(LPCTSTR pStrFontName, int nSize, bool bBold, bool bUnderline, bool bItalic);
    DWORD GetCustomFontCount() const;
    HFONT AddFont(LPCTSTR pStrFontName, int nSize, bool bBold, bool bUnderline, bool bItalic);
    bool RemoveFont(HFONT hFont);
    void RemoveAllFonts();
    HFONT GetFont(int index);

private:
    HFONT m_DefaultFontInfo;
    CStdPtrArray m_aCustomFonts;
};

} // namespace SdkLayout

#endif // __UIMANAGER_H__
