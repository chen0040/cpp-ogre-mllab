/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://ogre.sourceforge.net/

Copyright  2000-2002 The OGRE Team
Also see acknowledgements in Readme.html

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
-----------------------------------------------------------------------------
*/

/**
    @file
        LandScape.h
    @brief
        Specialisation of OGRE's framework application to show the
        LandScape rendering plugin
*/

using namespace Ogre;


ColourValue g_DayColor;


#include "PagingLandScape2Application.h"
#include "PagingLandScape2FrameListener.h"
#include "PagingLandScape2Terrainlistener.h"


#include "FrameListener.h"


class myPagingLandScapeApplication : public PagingLandScapeApplication
{
    public:
        //-----------------------------------------------------------------------
		myPagingLandScapeApplication() : 
		  PagingLandScapeApplication()
	    {
		    g_DayColor = ColourValue(0.57421875, 0.640625, 0.9921875);
	    }
        //-----------------------------------------------------------------------
    	~myPagingLandScapeApplication()
        {
        }

    protected:
		
        //-----------------------------------------------------------------------
    	virtual void createFrameListener(void)
	    {
		    mPagingFrameListener= new myPagingLandScapeFrameListener(mWindow,
                                    mCamera, mLight, mLightNode, 
                                    false, true);
		    mRoot->addFrameListener(mPagingFrameListener);
	    }
        
        //-----------------------------------------------------------------------
    	virtual void createViewports(void)
	    {
			PagingLandScapeApplication::createViewports();
			mWindow->getViewport (0)->setBackgroundColour( g_DayColor );
		}        
};


