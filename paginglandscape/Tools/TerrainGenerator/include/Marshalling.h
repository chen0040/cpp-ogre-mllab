#pragma once

#include <vcclr.h>
#include "OgrePrerequisites.h"

using namespace System;
using namespace System::Runtime::InteropServices;

//If Ogre is compiled with Unicode strings (OGRE_WCHAR_T_STRINGS=1) it will speed up
//string conversions
#if OGRE_WCHAR_T_STRINGS
#define DECLARE_OGRE_STRING(nvar,mstr) \
    pin_ptr<const wchar_t> p_##nvar = PtrToStringChars(mstr); \
    Ogre::String nvar( p_##nvar );
#define TO_CLR_STRING(ogrestr) Marshal::PtrToStringUni(static_cast<IntPtr>((wchar_t*)ogrestr.c_str()))
#else
#define DECLARE_OGRE_STRING(nvar,mstr) \
    IntPtr p_##nvar = Marshal::StringToHGlobalAnsi(mstr); \
    Ogre::String nvar( static_cast<char*>(p_##nvar.ToPointer()) ); \
    Marshal::FreeHGlobal( p_##nvar );
#define TO_CLR_STRING(ogrestr) Marshal::PtrToStringAnsi(static_cast<IntPtr>((char*)ogrestr.c_str()))
#endif