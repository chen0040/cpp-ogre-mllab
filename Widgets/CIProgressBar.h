#ifndef _H_ML_LAB_CI_PROGRESS_BAR_H
#define _H_ML_LAB_CI_PROGRESS_BAR_H

#include "CIWidget.h"

class CIProgressBar : public CIWidget
{
public:
	CIProgressBar(const std::string& rootId, CIWidget* parentWidget, CEGUI::Window* parentWindow,  float width, float height, float labelWidth);
	virtual ~CIProgressBar();

protected:
	virtual void create();

public:
	virtual void setProgress(float value);
	virtual float getProgress() const;

public:
	void setLabel(const std::string& label);

protected:
	CEGUI::ProgressBar* mProgressBar;
	CEGUI::DefaultWindow* mLabel;
	float mWidth;
	float mHeight;
	float mLabelWidth;
};
#endif