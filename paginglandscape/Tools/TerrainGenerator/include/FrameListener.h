#ifndef FRAMELISTENER_H
#define FRAMELISTENER_H

#include "Ogre.h"

ref struct FrameEvent 
{ 
   Ogre::Real timeSinceLastEvent; 
   Ogre::Real timeSinceLastFrame; 

   FrameEvent( Ogre::Real timeEvent, Ogre::Real timeFrame) 
      : timeSinceLastEvent(timeEvent), timeSinceLastFrame(timeFrame) 
   { 
   } 
};

interface class IFrameListener 
{
public:
   bool FrameStarted(FrameEvent^ evt); 
   bool FrameEnded(FrameEvent^ evt); 
};

class FrameListener_Proxy : public Ogre::FrameListener//, public RenderTargetListener
{
	gcroot<IFrameListener^> _managed;

public:
	FrameListener_Proxy( IFrameListener^ listener ) : _managed(listener)
	{
	}

	virtual bool frameStarted(const Ogre::FrameEvent& evt)
   	{
      		return _managed->FrameStarted(gcnew 
				FrameEvent(evt.timeSinceLastEvent, evt.timeSinceLastFrame));
   	}

   	virtual bool frameEnded(const Ogre::FrameEvent& evt)
   	{
      		return _managed->FrameEnded(gcnew 
				FrameEvent(evt.timeSinceLastEvent, evt.timeSinceLastFrame));
   	}

	/*
	virtual void preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
    {
        // Hide plane 
        mPlaneEnt->setVisible(false);

    }

    virtual void postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
    {
        // Show plane 
        mPlaneEnt->setVisible(true);
    }
	*/
};

#endif
