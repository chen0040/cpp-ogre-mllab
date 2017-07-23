/***************************************************************************
  OgreIPLData2D_HeightField.cpp 

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

***************************************************************************/

#include "OgreIPLData2D_HeightField.h"

#include "OgreIPLOptions.h"

#include <OgreStringConverter.h>
#include <OgreException.h>

namespace Ogre
{

#define BYTESPERPIXEL 4

//-----------------------------------------------------------------------
IPLData2D_HeightField::IPLData2D_HeightField( )
	: IPLData2D( )
{
	mImage = 0;
}

//-----------------------------------------------------------------------
IPLData2D_HeightField::~IPLData2D_HeightField( )
{
	unload( );
}

//-----------------------------------------------------------------------
float IPLData2D_HeightField::getHeight( const float x, const float z )
{
	const int xp = ( ( int )x + mSize ) % mSize;
	const int zp = ( ( ( int )z + mSize ) % mSize ) * mSize;
	// height data located in alpha channel
	return ( float )mImage->getData( )[ ( zp + xp ) * BYTESPERPIXEL + BYTESPERPIXEL - 1 ];
}

//-----------------------------------------------------------------------
float IPLData2D_HeightField::getMaxHeight( void )
{
	return 256.0f;
}

//-----------------------------------------------------------------------
void IPLData2D_HeightField::getNormalAt( const float x, const float z, Vector3* result )
{
	const int xp = ( ( int )x + mSize ) % mSize;
	const int zp = ( ( ( ( int )z + mSize ) % mSize ) * mSize + xp ) * BYTESPERPIXEL;

	// normal vector located in RGB channels
	// vector is in compressed format  0 -> 255 and needs to be uncompressed to -1 -> +1
	result->x = ( ( float )( mImage->getData( )[ zp ] ) ) / 255.0f * 2.0f - 1.0f;
	result->y = ( ( float )( mImage->getData( )[ zp + 1] ) ) / 255.0f * 2.0f - 1.0f;
	result->z = ( ( float )( mImage->getData( )[ zp + 2] ) ) / 255.0f * 2.0f - 1.0f;
}

//-----------------------------------------------------------------------
void IPLData2D_HeightField::preLoad( void )
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
void IPLData2D_HeightField::_load( float mX, float mZ )
{
	if ( mImage == 0 )
	{
		mImage = new Image( );
	}

	mImage->load( IPLOptions::getSingletonPtr( )->landscape_filename + "." + StringConverter::toString( mZ ) + "." + StringConverter::toString( mX ) + "." + IPLOptions::getSingletonPtr( )->landscape_extension );

	//check to make sure it's 2^n + 1 size.
	if ( mImage->getWidth( ) != mImage->getHeight( ) ||	! _checkSize( mImage -> getWidth( ) ) )
	{
		String err = "Error: Invalid heightmap size : " +
			StringConverter::toString( mImage -> getWidth( ) ) +
			"," + StringConverter::toString( mImage -> getHeight( ) ) +
			". Should be 2^n+1, 2^n+1";
		Except( Exception::ERR_INVALIDPARAMS, err, "IPLData2D_HeightField::load" );
	}

	// check image format: must be 4 bytes RGBA
	int elemByteCount = mImage->getNumElemBytes( mImage->getFormat( ) );
	if ( elemByteCount != BYTESPERPIXEL )
	{
		String err = "Error: Invalid heightmap channel byte count : " +
			StringConverter::toString( elemByteCount ) 
			+ ". Should be " + StringConverter::toString( BYTESPERPIXEL );
		Except( Exception::ERR_INVALIDPARAMS, err, "IPLData2D_HeightField::load" );
	}

	mSize = IPLOptions::getSingletonPtr( )->PageSize;
	if ( mSize != mImage -> getWidth( ) )
	{
		Except ( Exception::ERR_INVALIDPARAMS, "Error: Declared World size <> Height Map Size.", "IPLData2D_HeightField::load" );
	}
	mMax = mSize * mSize + 1;

	mIsLoaded = true;
}

//-----------------------------------------------------------------------
void IPLData2D_HeightField::_load( void )
{
}

//-----------------------------------------------------------------------
void IPLData2D_HeightField::_unload( void )
{
	if ( mImage != NULL )
	{
		delete mImage;
		mImage = NULL;
		mIsLoaded = false;
	}
}

//-----------------------------------------------------------------------
bool IPLData2D_HeightField::_checkSize( int s ) const
{
	if ( ( ( s - 1 ) % 2 ) == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

//-----------------------------------------------------------------------
inline float IPLData2D_HeightField::_Max( int a, int b ) const
{
	return ( ( a > b ) ? a : b );
}

} //namespace
