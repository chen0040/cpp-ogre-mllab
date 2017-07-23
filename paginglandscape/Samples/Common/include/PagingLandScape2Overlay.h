#ifndef CursorOverlayElement_H
#define CursorOverlayElement_H


class CursorOverlayElement : public PanelOverlayElement
{

    public:

        //---------------------------------------------------------------------
        CursorOverlayElement(const String& name) :
                    PanelOverlayElement(name), 
                    mOffsetX(0.0),
                    mOffsetY(0.0)
        {
            mVisible = false; // cursors are initially hidden

         
            setWidth(0.01f);
            setHeight(0.01f);
            
        }
        //---------------------------------------------------------------------
        const String& getTypeName(void) const
        {
            return msTypeName;
        }
        //---------------------------------------------------------------------
        void show()
        {
//            if (!mVisible) 
//            {
//                OverlayManager &om = OverlayManager::getSingleton();
                setLeft(250 - mOffsetX);
                setTop(250 - mOffsetY);
//                //om.addMouseMotionListener(this);
//            }
            OverlayElement::show();
        }
        //---------------------------------------------------------------------
        void hide(void)
        {
//            if (mVisible) 
//            {           
//                //OverlayManager::getSingleton().removeMouseMotionListener(this);
//            }
            OverlayElement::hide();
        }
        //---------------------------------------------------------------------
        void setOffsetX(Real x)
        {
            setLeft(mLeft + mOffsetX - x);
            mOffsetX = x;
        }
        //---------------------------------------------------------------------
        void setOffsetY(Real y)
        {
            setTop(mTop + mOffsetY - y);
            mOffsetY = y;
        }
        //---------------------------------------------------------------------
        OverlayElement* findElementAt(Real x, Real y) // relative to parent
        {
            return NULL;// override this so it won't find itself!
        }
        //---------------------------------------------------------------------
        void mouseMoved(const OIS::MouseEvent& e)
        {
            setLeft(e.state.X.abs - mOffsetX);
            setTop(e.state.Y.abs - mOffsetY);
        }
        //---------------------------------------------------------------------
        void mouseDragged(const OIS::MouseEvent& e)
        {
            mouseMoved (e);
        }      

    protected :
        Real mOffsetX, mOffsetY;
};
#endif //CursorOverlayElement_H
