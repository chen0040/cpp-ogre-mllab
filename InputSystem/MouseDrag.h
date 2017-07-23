#ifndef _H_ML_LAB_MOUSE_DRAG_H
#define _H_ML_LAB_MOUSE_DRAG_H

#include <Ogre.h>
#include <OIS/OIS.h>
#include <CEGUI/CEGUI.h>
#include <boost/bind.hpp>
#include <boost/signal.hpp>
#include "SelectionRectangle.h"

using namespace Ogre;

class MouseDrag
{
public:
	typedef boost::signal<void (MovableObject*)> signal_s;
	typedef boost::signal<void ()> signal_ds;

public:
	MouseDrag();
	virtual ~MouseDrag();

protected:
	Vector2 mStartDrag;
	Vector2 mEndDrag;

protected:
	void dragStarted(const Vector2& pt);
	void drag(const Vector2& pt);
	void dragEnded();

public:
	void dragStarted(const OIS::MouseEvent& evt);
	void drag(const OIS::MouseEvent& evt);
	void dragEnded(const OIS::MouseEvent& evt);

public:
	boost::signals::connection subscribeEvent_onUnSelect(signal_ds::slot_function_type subscriber);
	boost::signals::connection subscribeEvent_onSelect(signal_s::slot_function_type subscriber);

public:
	void setCamera(Camera* cam) { mCamera=cam; }

protected:
	SelectionRectangle* mSelectionRect;
	PlaneBoundedVolumeListSceneQuery* mSelectRectQuery;

protected:
	signal_s mSigSelect;
	signal_ds mSigClear;
	Camera* mCamera;
};

#endif