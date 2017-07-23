/*
	This file is part of Navi, a library that allows developers to embed movable 
	'Navis' (Dynamic, HTML/JS/CSS-Driven GUI Overlays) within an Ogre3D application.

	Copyright (C) 2007 Adam J. Simmons
	http://www.agelessanime.com/Navi/

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef __NaviPlatform_H__
#define __NaviPlatform_H__
#if _MSC_VER > 1000
#pragma once
#endif

#if defined(NAVI_DYNAMIC_LIB) && (defined(__WIN32__) || defined(_WIN32))
#	if defined(NAVI_NONCLIENT_BUILD)
#		define _NaviExport __declspec( dllexport )
#	else
#		define _NaviExport __declspec( dllimport )
#	endif
#else
#	define _NaviExport
#endif

#endif