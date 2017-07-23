#include "NicknameDlg.h"
#include "GUIManager.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../ScriptEngine/ScriptManager.h"

NicknameDlg::NicknameDlg(const std::string& rootId, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
, mNicknameField(NULL)
{
	initializeComponents(rootId);
}

void NicknameDlg::subscribeEvents()
{
	mEventCancel=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&NicknameDlg::onCancel, this));
	mEventListSelectionChanged=mScriptListing->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&NicknameDlg::onSelectionChanged_ScriptListing, this));

	mEventGenerateNickname=mBtnGenerateNickname->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&NicknameDlg::onClicked_GenerateNickname, this));
	mEventSetNickname=mBtnSetNickname->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&NicknameDlg::onClicked_SetNickname, this));
	mEventRemoveNickname=mBtnRemoveNickname->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&NicknameDlg::onClicked_RemoveNickname, this));
}

void NicknameDlg::unsubscribeEvents()
{
	mEventCancel->disconnect();
	mEventListSelectionChanged->disconnect();

	mEventGenerateNickname->disconnect();
	mEventRemoveNickname->disconnect();
	mEventSetNickname->disconnect();
}

void NicknameDlg::showModal()
{
	setModalState(true);

	updateData(false);
	showWindow();
}

NicknameDlg::~NicknameDlg()
{
	if(mNicknameField != NULL)
	{
		delete mNicknameField;
		mNicknameField = NULL;
	}

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mParentWindow->removeChildWindow(mRootWindow);
	wm->destroyWindow(mRootWindow);
}

void NicknameDlg::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.4f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.3f)));
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText((CEGUI::utf8*)"Nickname for ScriptId");
	mRootWindow->hide();

	const float listingWidth=0.47f;
	const float listingHeight=0.7f;
	const float txtWidth=1.0f;
	const float txtHeight=0.1f;
	const float labelWidth=0.6f;
	const float labelWidth2=0.45f;
	const float chkWidth=0.91f;
	const float vgap=0.01f;
	const float hgap=0.01f;
	const float left=0.05f;
	const float top=0.1f;
	const float btnWidth=0.43f;
	float x=left;
	float y=top;

	y=top;
	x=left;
	CEGUI::Window* lblScriptListing=wm->createWindow(CIWidget::getGUIType("StaticText"), getUIId("lblScriptListing"));
	lblScriptListing->setText("Available Scripts");
	lblScriptListing->setSize(CEGUI::UVector2(cegui_reldim(listingWidth), cegui_reldim(txtHeight)));
	lblScriptListing->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	lblScriptListing->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	mRootWindow->addChildWindow(lblScriptListing);

	y+=(txtHeight+vgap);
	x=left;
	mScriptListing=static_cast<CEGUI::Listbox*>(wm->createWindow(CIWidget::getGUIType("Listbox"), getUIId("ScriptListing")));
	mScriptListing->setSize(CEGUI::UVector2(cegui_reldim(listingWidth), cegui_reldim(listingHeight)));
	mScriptListing->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mScriptListing->setMultiselectEnabled(true);
	mRootWindow->addChildWindow(mScriptListing);

	x+=(listingWidth + hgap);
	y=top;
	mNicknameField=new CITextFieldWidget(getUIId("txtNicknameField"), this, mRootWindow, btnWidth, txtHeight, 0.46f);
	mNicknameField->setLabel("Nickname:");
	mNicknameField->setPosition(x, y);

	y+=(txtHeight + vgap);
	mBtnGenerateNickname=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnGenerateNickname")));
	mBtnGenerateNickname->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(txtHeight)));
	mBtnGenerateNickname->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnGenerateNickname->setText("Generate nickname");
	mRootWindow->addChildWindow(mBtnGenerateNickname);

	y+=(txtHeight + vgap);
	mBtnSetNickname=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSetNickname")));
	mBtnSetNickname->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(txtHeight)));
	mBtnSetNickname->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSetNickname->setText("Set nickname");
	mRootWindow->addChildWindow(mBtnSetNickname);

	y+=(txtHeight + vgap);
	mBtnRemoveNickname=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnRemoveNickname")));
	mBtnRemoveNickname->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(txtHeight)));
	mBtnRemoveNickname->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnRemoveNickname->setText("Remove nickname");
	mRootWindow->addChildWindow(mBtnRemoveNickname);

	mParentWindow->addChildWindow(mRootWindow);
}

bool NicknameDlg::onCancel(const CEGUI::EventArgs& evt)
{
	setModalState(false);
	hideWindow();
	
	return true;
}

void NicknameDlg::updateData(bool validateAndSaved)
{
	if(validateAndSaved)
	{
		
	}
	else
	{
		mScriptListing->resetList();
		ScriptManager* sm=ScriptManager::getSingletonPtr();
		const std::vector<std::string>& scriptListings=sm->getScriptListings();
		size_t scriptListingCount=scriptListings.size();
		for(size_t k=0; k != scriptListingCount; k++)
		{
			CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(scriptListings[k], static_cast<CEGUI::uint>(k));
			item->setTooltipText(sm->getNickname(scriptListings[k]));
			item->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");

			if(k==0)
			{
				item->setSelected(true);
			}
			mScriptListing->addItem(item);
		}
	}
}

bool NicknameDlg::onSelectionChanged_ScriptListing(const CEGUI::EventArgs& evt)
{
	size_t itemCount=mScriptListing->getItemCount();
	if(mScriptListing->getSelectedCount() == 0 && itemCount > 0)
	{
		return true;
	}

	ScriptManager* sm=ScriptManager::getSingletonPtr();

	for(size_t i=0; i!=itemCount; ++i)
	{
		CEGUI::ListboxItem* item=mScriptListing->getListboxItemFromIndex(i);
		if(item->isSelected())
		{
			std::string scriptId(item->getText().c_str());
			
			if(sm->hasNickname(scriptId))
			{
				std::string nickname=sm->getNickname(scriptId);
				mNicknameField->setText(nickname);
			}
			else
			{
				mNicknameField->setText("NA");
			}
			break;
		}
	}

	
	return true;
}

CEGUI::ListboxItem* NicknameDlg::getSelectedListboxItem()
{
	size_t itemCount=mScriptListing->getItemCount();
	if(mScriptListing->getSelectedCount() == 0 && itemCount > 0)
	{
		return NULL;
	}

	ScriptManager* sm=ScriptManager::getSingletonPtr();

	for(size_t i=0; i!=itemCount; ++i)
	{
		CEGUI::ListboxItem* item=mScriptListing->getListboxItemFromIndex(i);
		if(item->isSelected())
		{
			return item;
		}
	}

	return NULL;
}

bool NicknameDlg::onClicked_GenerateNickname(const CEGUI::EventArgs& evt)
{
	CEGUI::ListboxItem* item=this->getSelectedListboxItem();
	if(item == NULL)
	{
		return true;
	}

	std::string scriptId(item->getText().c_str());

	if(scriptId.length() > 4)
	{
		scriptId.replace(0, scriptId.length()-4, "XXXX");
	}

	mNicknameField->setText(scriptId);
	return true;
}

bool NicknameDlg::onClicked_SetNickname(const CEGUI::EventArgs& evt)
{
	CEGUI::ListboxItem* item=this->getSelectedListboxItem();
	if(item == NULL)
	{
		return true;
	}

	std::string nickname=mNicknameField->getText();
	if(nickname.compare("NA")==0)
	{
		GUIManager::getSingletonPtr()->showMsgBox("Invalid nickname", "Nickname cannot be NA, please click generate nickname button first");
		return true;
	}

	ScriptManager::getSingletonPtr()->setNickname(item->getText().c_str(), nickname);

	item->setTooltipText(nickname);
	return true;
}

bool NicknameDlg::onClicked_RemoveNickname(const CEGUI::EventArgs& evt)
{
	CEGUI::ListboxItem* item=this->getSelectedListboxItem();
	if(item == NULL)
	{
		return true;
	}

	ScriptManager::getSingletonPtr()->removeNickname(item->getText().c_str());
	mNicknameField->setText("NA");

	return true;
}