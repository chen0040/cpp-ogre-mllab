/***************************************************************************
  OgreIPLIndexBuffer.cpp 

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

#include "OgreIPLIndexBuffer.h"

#include <OgreHardwareBufferManager.h>

namespace Ogre
{
//-----------------------------------------------------------------------
template<> IPLIndexBuffer* Singleton<IPLIndexBuffer>::ms_Singleton = 0;

//-----------------------------------------------------------------------
IPLIndexBuffer::IPLIndexBuffer( )
{

    if ( mLevelIndex.size() == 0 )
    {
        for ( int i = 0; i < 16; i++ )
        {

            mLevelIndex.push_back( IndexArray( ) );

            for ( int j = 0; j < 16; j++ )
            {
                mLevelIndex[ i ].push_back( NULL );
            }
        }
    }

}

//-----------------------------------------------------------------------
IPLIndexBuffer::~IPLIndexBuffer( )
{
/*
	for ( int i = 0; i < 16; i++ )
	{
		if ( mIndexes[ i ] != 0 )
		{
			//HardwareBufferManager::getSingleton( ).destroyIndexBuffer( mIndexes[ i ] );
			delete mIndexes[ i ];
			mIndexes[ i ] = NULL;
		}

	}
*/
}

//-----------------------------------------------------------------------
IPLIndexBuffer& IPLIndexBuffer::getSingleton( void )
{
	assert( ms_Singleton );
	return *ms_Singleton;
}

//-----------------------------------------------------------------------   
IndexData *IPLIndexBuffer::getIndexData( IPLRenderable* renderable )
{
	const int renderLevel = renderable->getRenderLevel( );

    int index_array = 0;


	IndexData* indexData;

	// ask if we have the index computed if not compute it.
    if ( mLevelIndex[ renderLevel ][ index_array ] != NULL )
    {
        indexData = mLevelIndex[ renderLevel ][ index_array ];
    }
    else
    {
	    const int step = 1 << renderLevel;
		// get 2^n
		int renderSize = renderable->getRenderSize();

		int numIndexes = ( 2 * ( renderSize / step + 1 ) + 2 ) * ( renderSize / step );
		//int numIndexes = 6 * renderSize * renderSize  / step / step;

		// should be 2^n + 1 for the rest of the calculations
		renderSize++;
        
        indexData = new IndexData;
        mLevelIndex[ renderLevel ][ index_array ] = indexData;

        indexData->indexBuffer = HardwareBufferManager::getSingleton( ).createIndexBuffer( HardwareIndexBuffer::IT_16BIT, numIndexes, HardwareBuffer::HBU_STATIC_WRITE_ONLY );

	    mIndexCache.mCache.push_back( indexData );

	    // lock the VBO so we can write to it
        unsigned short* pIdx = static_cast< unsigned short* >( indexData->indexBuffer->lock( 0, indexData->indexBuffer->getSizeInBytes( ), HardwareBuffer::HBL_DISCARD ) );

		// build triangle strip with degenerate triangle at end of each row
		bool flipStrip = false;

		for ( int i = 0; i < ( renderSize - 1 ); i += step )
        {
			if ( flipStrip ) // build triangle strip from right to left every second horizontal strip
			{
				for ( int j = renderSize - 1; j >= 0; j -= step)
				{
					*pIdx++ = ( unsigned short )( j + ( i + step ) * renderSize ); 
					*pIdx++ = ( unsigned short )( j + i * renderSize );
				}
				*pIdx++ = ( unsigned short )( ( i + step ) * renderSize );
				*pIdx++ = ( unsigned short )( ( i + step ) * renderSize );
			}
			else // build triangle strip from left to right
			{
				for ( int j = 0; j < renderSize; j += step )
				{
					//2 vertices for each step
					// use clock wise triangle winding
					*pIdx++ = ( unsigned short )( j + i * renderSize ); 
					*pIdx++ = ( unsigned short )( j + ( i + step ) * renderSize );
				}
				*pIdx++ = ( unsigned short )( ( i + step + 1 ) * renderSize - 1 );
				*pIdx++ = ( unsigned short )( ( i + step + 1 ) * renderSize - 1 );

			}
			// flip triangle strip on next iteration
			flipStrip = !flipStrip;
/*
			for ( int j = 0; j < ( renderSize - step ); j += step )
			{
				//left tri
				*pIdx++ = ( unsigned short )( j + i * renderSize );
				*pIdx++ = ( unsigned short )( j + ( i + step ) * renderSize );
				*pIdx++ = ( unsigned short )( step + j + i * renderSize );
				// right tri
				*pIdx++ = ( unsigned short )( step + j + i * renderSize );
				*pIdx++ = ( unsigned short )( j + ( i + step ) * renderSize );
				*pIdx++ = ( unsigned short )( step + j + ( i + step ) * renderSize );
			}
*/
        }
        indexData->indexCount = numIndexes;
	    indexData->indexStart = 0;

        indexData->indexBuffer->unlock( );
    }
	return indexData;
}

} //namespace
