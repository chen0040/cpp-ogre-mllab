/***************************************************************************
  OgreIPLData2D_HeightFieldTC.cpp  -  description
  -------------------
  begin                : Mon Oct 13 2003
  copyright            : (C) 2003 by Jose A Milan
  email                : spoke@supercable.es
***************************************************************************/

/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU Lesser General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
***************************************************************************/

#include "OgreIPLData2D_HeightFieldTC.h"
#include "OgreIPLOptions.h"

#include <OgreStringConverter.h>
#include <OgreException.h>

namespace Ogre
{

#define BYTESPERPIXEL 4

//-----------------------------------------------------------------------
IPLData2D_HeightFieldTC::IPLData2D_HeightFieldTC( )
	: IPLData2D( )
{
	mImage = 0;
	input_max =  3000.0f;
	input_min = 0.0f;
}

//-----------------------------------------------------------------------
IPLData2D_HeightFieldTC::~IPLData2D_HeightFieldTC( )
{
	unload( );
}

//-----------------------------------------------------------------------
float IPLData2D_HeightFieldTC::getHeight( const float x, const float z )
{
/*
    if ( mImage != 0 )
    {
        uint Pos = ( z * mSize ) * mBpp + x * mBpp;//4 bytes (mImage is RGBA)
        if ( mMax > Pos )
        {
            // height is in alpha channel
            return ( float )_decodeTC( mImage->getData( )[ Pos + ( mBpp - 1 ) ] );
        }
        else
        {	
            return 0.0f;
        }
    }
    else
    {
     return 0.0f;
    }
*/
	const int xp = ( ( int )x + mSize ) % mSize;
	const int zp = ( ( ( int )z + mSize ) % mSize ) * mSize;
	// height data located in alpha channel
	return ( float )_decodeTC( mImage->getData( )[ ( zp + xp ) * BYTESPERPIXEL + BYTESPERPIXEL - 1 ] );
}

//-----------------------------------------------------------------------
float IPLData2D_HeightFieldTC::getMaxHeight( void )
{
	return _decodeTC(256);
}

//-----------------------------------------------------------------------
Vector3 IPLData2D_HeightFieldTC::getNormalAt( const float x, const float z )
{
	if ( mImage != 0 )
	{
		uint Pos = ( z * mSize ) * mBpp + x * mBpp;//4 bytes ( mImage is RGBA )

		if ( mMax > Pos )
		{
			const float normalscale = 1 / 127.0f;
			return Vector3 ( ( ( float )( mImage->getData( )[ Pos + 0 ] ) - 128.0f ) * normalscale, 
				( ( float )( mImage->getData( )[ Pos + 0 ] ) - 128.0f ) * normalscale,
				( ( float )( mImage->getData( )[ Pos + 0 ] ) - 128.0f ) * normalscale );
		}
		else
		{
			return Vector3::UNIT_Y;
		}	
	}
	else
	{
		return Vector3::UNIT_Y;
	}	
}

//-----------------------------------------------------------------------
ColourValue IPLData2D_HeightFieldTC::getBase ( const float mX, const float mZ )
{
	return ColourValue::White;
}

//-----------------------------------------------------------------------
ColourValue IPLData2D_HeightFieldTC::getCoverage ( const float mX, const float mZ )
{
	return ColourValue::White;
}

//-----------------------------------------------------------------------
void IPLData2D_HeightFieldTC::preLoad( void )
{
	Image newImage;
	for ( int z = 0; z < IPLOptions::getSingleton( ).virtual_window_height; z++ )
	{
		for ( int x = 0; x < IPLOptions::getSingleton( ).virtual_window_width; x++ )
		{
			// preload height map
			newImage.load( IPLOptions::getSingleton( ).landscape_filename + "." + StringConverter::toString( z ) + "." +
				StringConverter::toString( x ) + "." + IPLOptions::getSingleton( ).landscape_extension );
		}
	}
}

//-----------------------------------------------------------------------
void IPLData2D_HeightFieldTC::_load( float mX, float mZ )
{
	//TODO: adaptar esto para que permita cargar mas de una vez.
    if ( mImage == 0 )
     {
        mImage = new Image( );
	 }

	mImage->load( IPLOptions::getSingleton( ).landscape_filename + "." + StringConverter::toString( mZ ) + "." + 
		StringConverter::toString( mX ) + "." + IPLOptions::getSingleton( ).landscape_extension );

	//check to make sure it's 2^n + 1 size.
	if ( mImage->getWidth( ) != mImage->getHeight( ) || !_checkSize( mImage->getWidth( ) ) )
	{
		String err = "Error: Invalid heightmap size : " +
			StringConverter::toString( mImage->getWidth( ) ) +
			"," + StringConverter::toString( mImage->getHeight( ) ) +
			". Should be 2^n+1, 2^n+1";
		Except( Exception::ERR_INVALIDPARAMS, err, "IPLData2D_HeightField::_load" );
	}

	if ( mImage->getFormat( ) != PF_A8R8G8B8 )
	{
		Except( Exception::ERR_INVALIDPARAMS, "Error: Image is not a RGBA image.", "IPLData2D_HeightField::_load" );
	}

	mSize = IPLOptions::getSingleton( ).PageSize;
	if ( mSize != mImage->getWidth( ) )
	{
		Except ( Exception::ERR_INVALIDPARAMS, "Error: Declared World size <> Height Map Size.", "IPLData2D_HeightField::_load" );
	}
	mBpp = mImage->getNumElemBytes( mImage->getFormat( ) );
	mMax = mSize * mSize * mBpp + 1;
}

//-----------------------------------------------------------------------
void IPLData2D_HeightFieldTC::_load( void )
{
	if ( mImage == 0 )
	{
		mImage = new Image( );
	}

	mImage->load( IPLOptions::getSingleton( ).landscape_filename + 
		"." + IPLOptions::getSingleton( ).landscape_extension );

	//check to make sure it's 2^n size.
	if ( mImage->getWidth( ) != mImage->getHeight( ) )
	{
		String err = "Error: Invalid heightmap size : " +
			StringConverter::toString( mImage->getWidth( ) ) +
			"," + StringConverter::toString( mImage->getHeight( ) ) +
			". Should be 2^n, 2^n";
		Except( Exception::ERR_INVALIDPARAMS, err, "IPLData2D_HeightFieldTC::_load" );
	}

	if ( mImage -> getFormat( ) != PF_L8 )
	{
		Except( Exception::ERR_INVALIDPARAMS, "Error: Image is not a gray scale image.", "IPLData2D_HeightFieldTC::_load" );
	}

	mSize = mImage->getWidth( );
	mMax = mSize * mSize + 1;
}

//-----------------------------------------------------------------------
void IPLData2D_HeightFieldTC::_unload( void )
{
	if ( mImage != 0 )
	{
		delete mImage;
		mImage = 0;
	}
}

//-----------------------------------------------------------------------
float IPLData2D_HeightFieldTC::_decodeTC( int encoded )
{
	float value = ( float )( encoded + 0.5f ) / 255;
	return value * ( input_max - input_min ) + input_min;
}

} //namespace
