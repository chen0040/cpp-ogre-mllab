#include "WebPage.h"

WebPage::WebPage(TiXmlElement* xmlElement)
{
	mURL=xmlElement->Attribute("url");
	mTransparentColor=xmlElement->Attribute("transparent_color");
	mMaskFile=xmlElement->Attribute("mask_file");
}

WebPage::~WebPage()
{

}
