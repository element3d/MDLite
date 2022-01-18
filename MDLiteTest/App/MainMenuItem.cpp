#include "MainMenuItem.h"

MainMenuItem::MainMenuItem(e3::Element* pParent)
	: MainMenuItemBase(pParent)
{

}

void MainMenuItem::SetIcon(const std::string& iconName)
{
	mIcon->SetName(iconName);
}

void MainMenuItem::SetTitle(const std::string& title, bool translate)
{
	mTitle->SetText(title, translate);
}