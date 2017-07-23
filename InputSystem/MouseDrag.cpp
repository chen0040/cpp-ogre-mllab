#include "MouseDrag.h"
#include "../GameEngine/Application.h"

MouseDrag::MouseDrag()
: mCamera(NULL)
{
	mSelectionRect=new SelectionRectangle("Default Drag Rect");
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	sm->getRootSceneNode()->createChildSceneNode()->attachObject(mSelectionRect);

	mSelectRectQuery=sm->createPlaneBoundedVolumeQuery(PlaneBoundedVolumeList());
}

MouseDrag::~MouseDrag()
{
	if(mSelectionRect != NULL)
	{
		delete mSelectionRect;
		mSelectionRect=NULL;
	}

	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	sm->destroyQuery(mSelectRectQuery);
}

void MouseDrag::dragStarted(const Vector2& pt)
{
	mStartDrag=pt;
	mEndDrag=mStartDrag;

	mSelectionRect->clear();
	mSelectionRect->setVisible(true);
}

void MouseDrag::dragStarted(const OIS::MouseEvent& evt)
{
	CEGUI::Point mousePos=CEGUI::MouseCursor::getSingletonPtr()->getPosition();
	dragStarted(Vector2(mousePos.d_x / float(evt.state.width), mousePos.d_y / float(evt.state.height)));
}

void MouseDrag::drag(const Vector2& pt)
{
	mEndDrag=pt;
	mSelectionRect->setCorners(mStartDrag, mEndDrag);
}

void MouseDrag::drag(const OIS::MouseEvent& evt)
{
	CEGUI::Point mousePos=CEGUI::MouseCursor::getSingletonPtr()->getPosition();
	drag(Vector2(mousePos.d_x / float(evt.state.width), mousePos.d_y / float(evt.state.height)));
}

void MouseDrag::dragEnded(const OIS::MouseEvent& evt)
{
	dragEnded();
}

void MouseDrag::dragEnded()
{
	mSelectionRect->setVisible(false);

	Real left=mStartDrag.x;
	Real right=mEndDrag.x;
	Real top=mStartDrag.y;
	Real bottom=mEndDrag.y;

	if(left > right)
	{
		Real temp=left;
		left=right;
		right=temp;
	}

	if(top > bottom)
	{
		Real temp=top;
		top=bottom;
		bottom=temp;
	}

	if((right-left) * (bottom-top) < 0.0001)
	{
		return;
	}

	mSigClear();
	PlaneBoundedVolume pbv=mCamera->getCameraToViewportBoxVolume(left, top, right, bottom);
	PlaneBoundedVolumeList pbvl;
	pbvl.push_back(pbv);
	mSelectRectQuery->setVolumes(pbvl);

	SceneQueryResult& result=mSelectRectQuery->execute();
	SceneQueryResultMovableList::iterator iter=result.movables.begin();
	SceneQueryResultMovableList::iterator iter_end=result.movables.end();
	for(; iter != iter_end; ++iter)
	{
		MovableObject* mo=*iter;
		if(mo->getName().substr(0, 5) != "tile[")
		{
			mSigSelect(mo);
		}
	}	
}

boost::signals::connection MouseDrag::subscribeEvent_onUnSelect(MouseDrag::signal_ds::slot_function_type subscriber)
{
	return mSigClear.connect(subscriber);
}
	
boost::signals::connection MouseDrag::subscribeEvent_onSelect(MouseDrag::signal_s::slot_function_type subscriber)
{
	return mSigSelect.connect(subscriber);
}


