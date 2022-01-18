#include "MDIcon.h"
#include <e3/Application.h>
#include <fstream>

std::map<std::string, std::string> MDIcon::sIconMap;
std::map<std::string, std::string> MDIcon::sIconMapOutlined;

MDIcon::MDIcon(e3::Element* pParent)
	: MDIconBase(pParent)
{
	SetFont("MDLite/icons/MaterialIcons-Regular.ttf");

	if (!sIconMap.size()) _InitIconMap();
}

MDIcon::MDIcon(const std::string& name, int size, const glm::vec4& color)
	: MDIcon(nullptr)
{
	SetName(name);
	MDIconBase::SetColor(color);
	SetWidth(size);
	SetHeight(size);
}

void MDIcon::SetColor(MDColor* pColor)
{
	mColor = pColor;
	MDIconBase::SetColor(*pColor);
}

void MDIcon::SetColor(const glm::vec4& color)
{
	mColor = nullptr;
	MDIconBase::SetColor(color);
}

void MDIcon::_InitIconMap()
{
	{
		std::string cp = GetApplication()->GetAssetManager()->GetAssetPath("MDLite/icons/MaterialIcons-Regular.codepoints");
		std::ifstream infile(cp);
		std::string name, code;
		while (infile >> name >> code)
		{
			sIconMap[name] = code;
		}
	}
	{
		std::string cp = GetApplication()->GetAssetManager()->GetAssetPath("MDLite/icons/MaterialIconsOutlined-Regular.codepoints");
		std::ifstream infile(cp);
		std::string name, code;
		while (infile >> name >> code)
		{
			sIconMapOutlined[name] = code;
		}
	}

	return;
}

void MDIcon::SetName(const std::string& name)
{
	mName = name;
	// mNameUpdated = true;
	if (sIconMap.find(mName) == sIconMap.end())
	{
		printf("MaterialDesign: icon with name %s was not found.\n", mName.c_str());
		return;
	}
	SetCharcode(sIconMap[mName]);
/*//	if (mNameUpdated)
	{
		switch (mIconType)
		{
		case EMDIconType::Regular:
			SetCharcode(sIconMap[mName]);
			break;
		case EMDIconType::Outlined:
			SetCharcode(sIconMapOutlined[mName]);
			break;
		default:
			break;
		}

		mNameUpdated = false;
	}*/
}

std::string MDIcon::GetName()
{
	return mName;
}

void MDIcon::Render()
{
	if (mColor)	MDIconBase::SetColor(*mColor);
	MDIconBase::Render();
}