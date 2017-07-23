#include "DebugTextOverlay.h"

DebugTextOverlay::DebugTextOverlay(char* name)
{
	mOverlay = OverlayManager::getSingleton().getByName(name);
	mOverlay->hide();
}

DebugTextOverlay::~DebugTextOverlay()
{
	
}

void DebugTextOverlay::UpdateTextOverlay()
{
	// update stats when necessary
    try {
		OverlayManager::getSingleton().getOverlayElement("PlayerLocation")->setCaption("");		
    }
    catch(...)
    {
        // ignore
    }
}