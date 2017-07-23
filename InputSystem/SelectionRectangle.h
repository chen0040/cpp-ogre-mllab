#ifndef _H_SELECTION_RECTANGLE_H
#define _H_SELECTION_RECTANGLE_H

#include <Ogre.h>

using namespace Ogre;

class SelectionRectangle : public ManualObject
{
public:
	SelectionRectangle(const String& name)
		: ManualObject(name)
	{
		setRenderQueueGroup(RENDER_QUEUE_OVERLAY);
		setUseIdentityView(true);
		this->setUseIdentityProjection(true);
		this->setQueryFlags(0);
	}

public:
	void setCorners(float left, float top, float right, float bottom)
	{
		left=left*2-1;
		right=right*2-1;
		top=1-top*2;
		bottom=1-bottom*2;
		clear();
		begin("", RenderOperation::OT_LINE_STRIP);
			position(left, top, -1);
			position(right, top, -1);
			position(right, bottom, -1);
			position(left, bottom, -1);
			position(left, top, -1);
		end();

		AxisAlignedBox AABB;
		AABB.setInfinite();
		this->setBoundingBox(AABB);
	}
	void setCorners(Vector2 start, Vector2 end)
	{
		setCorners(start.x, start.y, end.x, end.y);
	}
};

#endif