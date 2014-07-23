# Microsoft Developer Studio Project File - Name="SdkLayout" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=SdkLayout - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SdkLayout.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SdkLayout.mak" CFG="SdkLayout - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SdkLayout - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "SdkLayout - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SdkLayout - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../output/SdkLayout_Release_VC6"
# PROP Intermediate_Dir "../output/SdkLayout_Release_VC6"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR- /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../bin/SdkLayout.lib"

!ELSEIF  "$(CFG)" == "SdkLayout - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../output/SdkLayout_Debug_VC6"
# PROP Intermediate_Dir "../output/SdkLayout_Debug_VC6"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD CPP /nologo /MTd /W3 /Gm /GR- /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Yu"StdAfx.h" /FD /GZ  /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../bin/SdkLayout_D.lib"

!ENDIF 

# Begin Target

# Name "SdkLayout - Win32 Release"
# Name "SdkLayout - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;asm"
# Begin Source File

SOURCE=.\UIContainer.cpp
# End Source File
# Begin Source File

SOURCE=.\UIContainer.h
# End Source File
# Begin Source File

SOURCE=.\UIControl.cpp
# End Source File
# Begin Source File

SOURCE=.\UIControl.h
# End Source File
# Begin Source File

SOURCE=.\UIDlgBuilder.cpp
# End Source File
# Begin Source File

SOURCE=.\UIDlgBuilder.h
# End Source File
# Begin Source File

SOURCE=.\UIHorizontalLayout.cpp
# End Source File
# Begin Source File

SOURCE=.\UIHorizontalLayout.h
# End Source File
# Begin Source File

SOURCE=.\UIManager.cpp
# End Source File
# Begin Source File

SOURCE=.\UIManager.h
# End Source File
# Begin Source File

SOURCE=.\UIMarkup.cpp
# End Source File
# Begin Source File

SOURCE=.\UIMarkup.h
# End Source File
# Begin Source File

SOURCE=.\UIVerticalLayout.cpp
# End Source File
# Begin Source File

SOURCE=.\UIVerticalLayout.h
# End Source File
# Begin Source File

SOURCE=.\Utils.cpp
# End Source File
# Begin Source File

SOURCE=.\Utils.h
# End Source File
# End Group
# Begin Group "Others"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\SdkLayout.cpp
# End Source File
# Begin Source File

SOURCE=.\SdkLayout.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "SdkLayout - Win32 Release"

!ELSEIF  "$(CFG)" == "SdkLayout - Win32 Debug"

# ADD CPP /Yc"StdAfx.h"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# End Target
# End Project
