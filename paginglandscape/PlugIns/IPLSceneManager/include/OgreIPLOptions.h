/***************************************************************************
	OgreIPLOptions.h  

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

#ifndef __IPLOPTIONS_H__
#define __IPLOPTIONS_H__

#include <OgrePrerequisites.h>
#include <OgreString.h>
#include <OgreSingleton.h>

#include <OgreVector3.h>
#include <OgreColourValue.h>

namespace Ogre
{

/**
  * A simple class for encapsulating parameters passed in when initializing a LandScapeRenderable
  */

class IPLOptions : public Singleton< IPLOptions >
{
public:
	IPLOptions( void );

	~IPLOptions( void );

	void load( const String& filename );

	bool setOption( const String& strKey, const void* pValue );

	bool getOption( const String& strKey, void* pDestValue );

	bool hasOption( const String& strKey );

	bool getOptionValues( const String& strKey, std::list<SDDataChunk>& refValueList );

	bool getOptionKeys( std::list<String>& refKeys );

	String landscape_filename;			// File name for the data 2D
	String landscape_extension;			// Extension for the data 2D

	String mData2DFormat;				// Format for the Data 2D file
	String mTextureFormat;				// Format for the Texture file

	String mMapTextureName;				// File name for the texture
	String mMapTextureExt;				// Extension for the texture

	String mDetailTextureName;			// File name for the detail texture
	String mDetailTextureExt;			// Extension for the detail texture
	float mPatchDetailRepeat;			// Number of times we want the detail texture to repeat

	int PageSize;						// size of the page.
	int mTileLOD;						// Initial value for LOD
	int mPatchLOD;						// 2^mPatchLOD gives the size of the Patch within a Tile
	int world_height;					// world page height, from 0 to height
	int world_width;					// world page width, from 0 to width
	int virtual_window_width;			// window width in pages looking into virtual world
	int virtual_window_height;			// window height in pages looking into virtual world

	Vector3 scale;

	float cameraThreshold;				// If the last camera position is >= the the scene is trasverse again.
	float visibilityRadiusSquared;		// radius of pages that are visible through camera 
	
	bool lit;
	bool colored;
	bool mPreloadCache;

	int maxValue;						//Compression range for the TC height field
	int minValue;

	ColourValue matColor[4];
	Real matHeight[1];

	/** Override standard Singleton retrieval.
		@remarks
			Why do we do this? Well, it's because the Singleton implementation is in a .h file,
			which means it gets compiled into anybody who includes it. This is needed for the Singleton
			template to work, but we actually only want it compiled into the implementation of the
			class based on the Singleton, not all of them. If we don't change this, we get link errors
			when trying to use the Singleton-based class from an outside dll.
		@par
			This method just delegates to the template version anyway, but the implementation stays in this
			single compilation unit, preventing link errors.
	*/
	static IPLOptions& getSingleton( void );
    static IPLOptions* getSingletonPtr( void );

private:

	ColourValue _getAvgColor(const String tex);

};

}

#endif
