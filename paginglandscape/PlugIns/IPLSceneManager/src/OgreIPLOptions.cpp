/***************************************************************************
  OgreIPLOptions.cpp  

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

#include "OgreIPLOptions.h"

#include <OgreConfigFile.h>
#include <OgreSDDataChunk.h>
#include <OgreImage.h>

namespace Ogre
{

//-----------------------------------------------------------------------
template<> IPLOptions* Singleton<IPLOptions>::ms_Singleton = 0;

//-----------------------------------------------------------------------
IPLOptions::IPLOptions( void )
{
	landscape_filename = "";
	landscape_extension = "";

	mData2DFormat = "";
	mTextureFormat = "";

	mMapTextureName = "";
	mMapTextureExt = "";
	
	mDetailTextureName = "";
	mDetailTextureExt = "";

	PageSize = 257;
	mTileLOD = 6;
	world_width = -1;
	world_height = -1;
	virtual_window_width = -1;
	virtual_window_height = -1;
	mPatchLOD = 5;
	mPatchDetailRepeat = 5;

    scale = Vector3( 1, 1, 1 );
    lit = false;
    colored = false;
	mPreloadCache = false;
	cameraThreshold = 5;

	maxValue = 5000;
	minValue = 0;

	for (int i = 0; i < 4; i++)
	{
		matColor[i] = ColourValue();
	}
	matHeight[0] = 0;
	matHeight[1] = 0;
};

//-----------------------------------------------------------------------
IPLOptions::~IPLOptions( void )
{
}

//-----------------------------------------------------------------------
void IPLOptions::load( const String& filename )
{
	/* Set up the options */
	ConfigFile config;
	String val;

	config.load( filename );

	landscape_filename = config.getSetting( "LandScapeFileName" );
	landscape_extension = config.getSetting( "LandScapeExtension" );
	
	mData2DFormat = config.getSetting( "Data2DFormat" );
	mTextureFormat = config.getSetting( "TextureFormat" );

	mMapTextureName = config.getSetting( "MapTextureName" );
	mMapTextureExt = config.getSetting( "MapTextureExtension" );

	mDetailTextureName = config.getSetting( "DetailTextureName" );
	mDetailTextureExt = config.getSetting( "DetailTextureExtension" );

	if ( StringUtil::startsWith( mData2DFormat.c_str(), "HeightFieldTC", false) )
	{
		maxValue = (int) StringUtil::toReal( config.getSetting( "MaxValue" ) );
		minValue = (int) StringUtil::toReal( config.getSetting( "MinValue" ) );
	}
	else
	{
		maxValue = 255 * scale.y;
		minValue = 0 * scale.y;
	}

	matColor[0] = _getAvgColor( config.getSetting( "SplatFilename0" ) );
	matColor[1] = _getAvgColor( config.getSetting( "SplatFilename1" ) );
	matColor[2] = _getAvgColor( config.getSetting( "SplatFilename2" ) );
	matColor[3] = _getAvgColor( config.getSetting( "SplatFilename3" ) );

	matHeight[0] = StringUtil::toReal( config.getSetting( "MaterialHeight1" ) );
	matHeight[0] = ( matHeight[0] / 255 ) * ( maxValue - minValue );

	matHeight[1] = StringUtil::toReal( config.getSetting( "MaterialHeight2" ) );
	matHeight[1] = ( matHeight[1] / 255 ) * ( maxValue - minValue );

	val = config.getSetting( "CameraThreshold" );
	if ( !val.empty( ) )
	{
		cameraThreshold = atof( val.c_str( ) );
	}
	// To avoid the use of a square root.
	cameraThreshold *= cameraThreshold;
		
	val = config.getSetting( "ScaleX" );
	if ( !val.empty( ) )
	{
		scale.x = atof( val.c_str( ) );
	}

	val = config.getSetting( "ScaleY" );
	if ( !val.empty( ) )
	{
		scale.y = atof( val.c_str( ) );
	}

	val = config.getSetting( "ScaleZ" );
	if ( !val.empty( ) )
	{
		scale.z = atof( val.c_str( ) );
	}

	val = config.getSetting( "PatchDetailRepeat" );
	if ( !val.empty( ) )
	{
		mPatchDetailRepeat = atof( val.c_str( ) );
	}

	val = config.getSetting( "Height" );
	if ( !val.empty( ) )
	{
		world_height = atoi( val.c_str( ) );
	}

	val = config.getSetting( "Width" );
	if ( !val.empty( ) )
	{
		world_width = atoi( val.c_str( ) );
	}

	val = config.getSetting( "VirtualWindowHeight" );
	if ( !val.empty( ) )
	{
		virtual_window_height = atoi( val.c_str( ) );
	}

	val = config.getSetting( "VirtualWindowWidth" );
	if ( !val.empty( ) )
	{
		virtual_window_width = atoi( val.c_str( ) );
	}

	val = config.getSetting( "PageSize" );
	if ( !val.empty( ) )
	{
		PageSize = atoi( val.c_str( ) );
	}

	val = config.getSetting( "TileLOD" );
	if ( !val.empty( ) )
	{
		mTileLOD = atoi( val.c_str( ) );
	}

	val = config.getSetting( "PatchLOD" );
	if ( !val.empty( ) )
	{
		mPatchLOD = atoi( val.c_str( ) );
	}

	colored = ( config.getSetting( "VertexColors" ) == "yes" );

	lit = ( config.getSetting( "VertexNormals" ) == "yes" );

	if ( config.getSetting( "PreloadCache" ) == "yes" )
	{
		mPreloadCache = true;
	}

	visibilityRadiusSquared = ( scale.x + scale.z ) / 2.0f * ( float )( PageSize - 1 ) * atof( config.getSetting( "VisibilityPageRadius").c_str( ) );
	visibilityRadiusSquared *= visibilityRadiusSquared  ;
}

//-----------------------------------------------------------------------
bool IPLOptions::setOption( const String& strKey, const void* pValue )
{
	return false;
}

//-----------------------------------------------------------------------
bool IPLOptions::getOption( const String& strKey, void* pDestValue )
{
	// Some options proposed by Praetor
	if ( strKey == "Width" )
	{
		* static_cast < int * > ( pDestValue ) = world_width;
		return true;
	}
	if ( strKey == "Height" )
	{
		* static_cast < int * > ( pDestValue ) = world_height;
		return true;
	}
	if ( strKey == "PageSize" )
	{
		* static_cast < int * > ( pDestValue ) = PageSize;
		return true;
	}
	if ( strKey == "ScaleX" )
	{
		* static_cast < Real * > ( pDestValue ) = scale.x;
		return true;
	}
	if ( strKey == "ScaleY" )
	{
		* static_cast < Real * > ( pDestValue ) = scale.y;
		return true;
	}
	if ( strKey == "ScaleZ" )
	{
		* static_cast < Real * > ( pDestValue ) = scale.z;
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------
bool IPLOptions::hasOption( const String& strKey )
{
	// Some options proposed by Praetor
	if ( strKey == "Width" )
	{
		return true;
	}
	if ( strKey == "Height" )
	{
		return true;
	}
	if ( strKey == "PageSize" )
	{
		return true;
	}
	if ( strKey == "ScaleX" )
	{
		return true;
	}
	if ( strKey == "ScaleY" )
	{
		return true;
	}
	if ( strKey == "ScaleZ" )
	{
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------
bool IPLOptions::getOptionValues( const String& strKey, std::list<SDDataChunk>& refValueList )
{
	return false;
}

//-----------------------------------------------------------------------
bool IPLOptions::getOptionKeys( std::list<String>& refKeys )
{
	// Some options from Praetor
	refKeys.push_back( "Width" );
	refKeys.push_back( "Height" );
	refKeys.push_back( "PageSize" );
	refKeys.push_back( "ScaleX" );
	refKeys.push_back( "ScaleY" );
	refKeys.push_back( "ScaleZ" );
	return true;
}

//-----------------------------------------------------------------------
IPLOptions& IPLOptions::getSingleton(void)
{
	assert( ms_Singleton );
	return *ms_Singleton;
}

//-----------------------------------------------------------------------
IPLOptions* IPLOptions::getSingletonPtr(void)
{
	return ms_Singleton;
}

//-----------------------------------------------------------------------
ColourValue IPLOptions::_getAvgColor(const String tex)
{
	Image img;
	img.load(tex);
	uint bpp = img.getNumElemBytes (img.getFormat ());
	const uchar* data = img.getData();
	int cr = 0, cg = 0, cb = 0, s = 0;
	for (int i = 0; i < (int)img.getSize(); i += bpp)
	{
		cr += data[i];
		cg += data[i+1];
		cb += data[i+2];
		s++;
	}
	cr /= s;
	cg /= s;
	cb /= s;
	ColourValue c(cr / 255.0, cg / 255.0, cb / 255.0, 1);
	return c;
}

} //namespace
