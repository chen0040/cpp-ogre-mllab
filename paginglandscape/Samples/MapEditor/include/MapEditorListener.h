
#ifndef MAP_EDITOR_LISTENER_H
#define MAP_EDITOR_LISTENER_H

#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"


#include "ExampleApplication.h"
#include "ExampleFrameListener.h"
#include "OgrePagingLandScapeRaySceneQuery.h"
#include "Line3D.h"
#include "DebugTextOverlay.h"

#include <map>

#include "OIS/OIS.h"
enum EditMode
{
    EditNothing = 0,
    EditDeformTerrain,
    EditPaintAlphaTerrain,
    EditPaintColorTerrain,
};

class MapEditorListener : 
    public FrameListener, 
    public OIS::KeyListener, 
	public OIS::MouseListener
{
private:
#ifdef _DEBUG
	const static short  AMOUNT_CURSOR_POINTS=36;
#else
	const static short  AMOUNT_CURSOR_POINTS=360;
#endif
	unsigned int		mCursorSize;
	Vector3			    mCursorPoints[AMOUNT_CURSOR_POINTS+1];
	Line3D*			    mCursor;
	unsigned int		mBrushSize;
	float		        mBrushStrength;

	SceneNode*		    mMainSceneNode;
	SceneNode*		    mCursorNode;
	Camera*			    mCamera;
	SceneManager*	    mScnMgr;
	RenderWindow*	    mWindow;

	OIS::Keyboard*	    mKeyboard;
	OIS::Mouse*			mMouse;
	OIS::InputManager*  mInputSystem;

	CEGUI::Renderer*    mGuiRenderer;
	DebugTextOverlay*	mDebugOverlay;

	bool			    mUseBufferedInputKeys, mUseBufferedInputMouse;
	bool			    rMouseDown;
	bool			    lMouseDown;

	bool			    endProgram;
	bool			    morphMode;

	RaySceneQuery*	    mRayQuery;
	RaySceneQuery*	    mRayCursorQuery;
	bool			    mClickActive;
    Real			    mClickX, mClickY;

    EditMode            mEditMode;

	Real 			    mTimeElapsed;
	Real			    mTimeUntilNextToggle ;
	Real			    mKeyRate;

	Real                mAmountMovedX;
	Real                mAamountMovedY; 

	Real          		mMoveSpeed;
	Degree        		mRotateSpeed;
	Vector3       		mTranslateVector;
	float         		mMoveScale;
	Degree        		mRotScale;
	unsigned int  		mKeyClickedNum;
	Radian        		mRotX, mRotY;

protected:
    //!overriden from FrameListener
	bool			frameStarted(const FrameEvent& evt);
	bool			frameEnded(const FrameEvent& evt);
	void			updateStats(void);

	bool mouseReleased(const OIS::MouseEvent& e, OIS::MouseButtonID id);
	bool mousePressed(const OIS::MouseEvent& e, OIS::MouseButtonID id);
	bool mouseMoved(const OIS::MouseEvent& e);

	bool keyPressed(const OIS::KeyEvent& e);
	bool keyReleased(const OIS::KeyEvent& e);


	void			handleKeyboardInput(const FrameEvent& evt);
	void			deform();

public:
	MapEditorListener(RenderWindow* win, 
					Camera* cam, 
					CEGUI::Renderer* renderer, 
                    const Ogre::String &terrainPath,
					bool useBufferedInputKeys = false, 
					bool useBufferedInputMouse = false);
	~MapEditorListener();

    void			setEditMode (const EditMode editMode);
	EditMode		getEditMode() { return mEditMode; }
	void			requestShutDown() { endProgram=true; }
	void			setMorphMode(const bool value);
	SceneManager*	getSceneManager() { return mScnMgr; }
	RaySceneQuery*	getCursorRay() { return mRayCursorQuery; }
	Vector3*		getCursorPoints() { return mCursorPoints; }
	short			getAmountOfCursorPoints() { return (short)AMOUNT_CURSOR_POINTS; }
	int				getBrushSize() { return mBrushSize; }
	int				getBrushStrength() { return mBrushStrength; }
	Line3D*			getCursor() { return mCursor; }
	void			setBrushSize(const int value);
	void			setBrushStrength(const float value) { mBrushStrength=value; }

	Vector3			mCursorPos;
	String				mTerrainPath;
};

#endif
