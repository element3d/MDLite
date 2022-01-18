#include "MDListTile.h"
#include "MDColors.h"

MDListTile::MDListTile(e3::Element* pParent)
	: MDListTileBase(pParent)
{

}

void MDListTile::SetLeading(e3::Element* pElement)
{
	mLeading->AddElement(pElement);
	mTitleBody->SetMarginLeft(0);
}

void MDListTile::SetTitle(const std::string& title, bool translate)
{
	if (!mTitleBody->GetNumChildren())
	{
		/*MD*/e3::Text* pTitle = new /*MD*/e3::Text();
		//pTitle->SetTextColor(GetTheme()->TextTheme.Subtitle1.Color);
		pTitle->SetFontSize(e3::Dim(16, 16, 48, 16, 16, 16));
		pTitle->SetText(title, translate);
		mTitleBody->AddElement(pTitle);
		return;
	}
	((e3::Text*)mTitleBody->GetChildren()[0])->SetText(title, translate);
}

void MDListTile::SetSubtitle(const std::string& subtitle, bool translate)
{
	if (mTitleBody->GetNumChildren() == 1)
	{
		/*MD*/e3::Text* pTitle = new /*MD*/e3::Text();
		pTitle->SetFontSize(14);
		pTitle->SetMarginTop(4);
		pTitle->SetTextColor(MDColors::Grey::Get("600"));
		//pTitle->SetTextColor(GetTheme()->TextTheme.Subtitle1.Color);
		pTitle->SetText(subtitle, translate);
		mTitleBody->AddElement(pTitle);
		return;
	}
	if (mTitleBody->GetNumChildren() < 1) return;

	((e3::Text*)mTitleBody->GetChildren()[1])->SetText(subtitle, translate);
}

void MDListTile::SetTrailing(e3::Element* pElement)
{
	mTrailing->AddElement(pElement);
}