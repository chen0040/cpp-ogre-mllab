/********************************************************************************
	OgreIPLData2D_Spline.cpp
	*****************************************************************************
	A NURBS-based heightfield generator for use with the IPLplugin
	
	Note that it could easily be adapted for use as a general NURBS surface
	generator.
	*****************************************************************************
	begin                : Sat Nov 9 2003
	copyright            : (C) 2003 Chris "Antiarc" Heald
	email                : antiarc@captionthis.com
********************************************************************************/

/********************************************************************************
*																				*
*   This program is free software; you can redistribute it and/or modify		*
*   it under the terms of the GNU Lesser General Public License as published by *
*   the Free Software Foundation; either version 2 of the License, or			*
*   (at your option) any later version.											*
*																				*
********************************************************************************/

#include "OgreIPLData2D_Spline.h"

#include "OgreIPLOptions.h"

#include <stdlib.h>
#include <iostream>
#include "time.h"
#include "math.h"

#include <OgreStringConverter.h>
#include <OgreException.h>
#include "OgreLogManager.h"

namespace Ogre
{

//-----------------------------------------------------------------------
IPLData2D_Spline::IPLData2D_Spline( )
	: IPLData2D( )
{
}

//-----------------------------------------------------------------------
IPLData2D_Spline::~IPLData2D_Spline( )
{
	if ( mSurface != 0 )
	{
		delete mSurface;
	}
	if ( mPoints != 0 )
	{
		delete[ ] mPoints;
	}
	mLoaded = false;
}

//-----------------------------------------------------------------------
float IPLData2D_Spline::getHeight( const float xt, const float zt )
{
	int Pos = ( xt * mResolution ) + zt;
	if ( mMax > Pos )
	{
		float retval = mSurface->getData( Pos ).y;
		return retval;
	}
	else
	{
		return 0.0;
	}
}             

//-----------------------------------------------------------------------
float IPLData2D_Spline::getMaxHeight( void )
{
	return 256.0f;
}

//-----------------------------------------------------------------------
void IPLData2D_Spline::preLoad( void )
{
}

//-----------------------------------------------------------------------
void IPLData2D_Spline::_load( float mX, float mZ )
{
	if ( !mLoaded )
	{
		int resolution	= IPLOptions::getSingleton( ).PageSize;
		mResolution		= resolution;
		mMax			= mResolution * mResolution;
		int pCount		= 50;
		int mDegree		= 3;
		float MAX		= 500;
		float MIN		= 0;
		int tessLevel	= mResolution;

		srand( time( NULL ) );
		int j = 0;
		int i = 0;

		mPoints = new Point4D[ pCount * pCount ];
		const int knotVecSize = pCount + mDegree + 1;
		float *knots = new float[ knotVecSize ];
		for ( i = 0; i < knotVecSize; i++ )
		{
			if ( i < mDegree )
			{
				knots[ i ] = 0;
			}
			else if ( i > knotVecSize - mDegree )
			{
				knots[ i ] = knotVecSize - ( 2 * mDegree ) + 1;
			}
			else
			{
				knots[ i ] = i - mDegree + 1;
			}
		}
		int dataSize = pCount * pCount;
		for ( i = 0; i < dataSize; i++ )
		{
			mPoints[ i ].x = ( int )i / pCount;
			mPoints[ i ].y = ( ( double )rand( ) / ( double )( MAX ) );
			mPoints[ i ].w = 1;
			mPoints[ i ].z = 0;//i % pCount;
		}
		mSurface = new CDRGNURBSSurface( );
		mSurface->Init( mDegree, mDegree, pCount, pCount, mPoints, knots, knots, tessLevel, tessLevel );
		mSurface->TessellateSurface( );
		delete[ ] knots;
		delete[ ] mPoints;
		mLoaded = true;
	}
}
//-----------------------------------------------------------------------
void IPLData2D_Spline::_load( void )
{
}

//-----------------------------------------------------------------------
void IPLData2D_Spline::_unload( void )
{
	if ( mSurface != 0 )
	{		
		delete mSurface;
	}
	mLoaded = false;
}

} //namespace
