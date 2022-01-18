#include "MainMenuItemBase.h"

#include <e3/ViewFactory.h>
#include "./MDLiteTestValues.h"

MainMenuItemBase::MainMenuItemBase(e3::Element* pParent)
	: MDInkWell(pParent)
{
        this->SetWidth(e3::Dim("450", "450", "450", "150", "150", "150"));
        this->SetHeight(e3::Dim("450", "450", "450", "150", "150", "150"));
        this->SetMargin(e3::Dim("30", "30", "30", "10", "10", "10"));
        this->SetOrientation((e3::EOrientation)1);
        this->SetBorderRadius(glm::vec4(5));
        this->SetBorderColor(MDTheme::Get()->PrimaryColor);
        this->SetBorderSize(e3::Dim("6", "6", "6", "2", "2", "2"));
        this->SetBackgroundColor(MDTheme::Get()->Surface);
        mIcon = new MDIcon();
        AddElement(mIcon);
        mIcon->SetName(_s(web_asset));
        mIcon->SetWidth(e3::Dim("108", "108", "108", "36", "36", "36"));
        mIcon->SetHeight(e3::Dim("108", "108", "108", "36", "36", "36"));
        mIcon->SetColor(MDTheme::Get()->PrimaryColor);
        mTitle = new MDText();
        AddElement(mTitle);
        mTitle->SetText("App bar");
        mTitle->SetTextColor(MDTheme::Get()->PrimaryColor);
        mTitle->SetFontSize(e3::Dim("52", "52", "52", "14", "14", "14"));
        mTitle->SetFontStyle((e3::EFontStyle)2);

}
