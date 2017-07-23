#ifndef DEBUG_TEXT_OVERLAY_H
#define DEBUG_TEXT_OVERLAY_H

#include "Ogre.h"

using namespace Ogre;

class DebugTextOverlay
{
private:
	Overlay*		mOverlay;
protected:
public:
					DebugTextOverlay(char* name);
					~DebugTextOverlay();
	void			UpdateTextOverlay();
};

#endif