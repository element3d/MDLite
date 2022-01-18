#include "MDMenu.h"

MDMenu::MDMenu(e3::Element* pParent)
	: MDMenuBase(pParent)
{

}

void MDMenu::Expand()
{
	//SetBackgroundColor(glm::vec4(0));
	//	mRipple->SetOpacity(0);

	// e3::Rect2f iconGeo = mIcon->GetGeometry();
	e3::Rect2f geo = GetGeometry();
	e3::DropdownBody* pBody = GetBody();
	pBody->SetTop(-0.75 * geo.height);
	pBody->SetLeft(-pBody->GetGeometry().width + 0.75 * geo.width);
	e3::Dropdown::Expand();
	e3::Rect2f bodyGeo = pBody->GetGeometry();

	e3::Animation* pA = new e3::Animation;
	pA->Start(0.15, 0, 1, [this, geo, pBody, bodyGeo](float v) {
		//pBody->SetScale(glm::vec3(std::min(1.0f, 1.5f * v), v, 1), e3::ETransformAlignment::TopRight);
		pBody->SetHeight(bodyGeo.height * v);
		//pBody->SetClipRect(e3::Rect2f(0, 0, bodyGeo.width, bodyGeo.height * v));
		//pBody->SetOpacity(v);
		for (int i = 0; i < pBody->GetNumChildren(); ++i)
		{
			//pBody->GetChildren()[i]->SetOpacity(v);
		}
		//pBody->SetHeight(v * geo.height);
	}, [bodyGeo, pBody]() {
		printf("sadfasd");
	});
}