#include "ListPage.h"
#include "MDListTile.h"

ListPage::ListPage(e3::Element* pParent)
	: ListPageBase(pParent)
{
	for (int i = 0; i < 20; ++i)
	{
		e3::Element* pA = new e3::Element();
		pA->SetHeight("95%");
		pA->SetAspectRatio(1);
		pA->SetShapeType(e3::EShapeType::Circle);
		pA->SetBackgroundColor(glm::vec4(20, 25, 200, 255));
		MDListTile* pTile = new MDListTile();
		pTile->SetLeading(pA);
		pTile->SetTitle("Item" + std::to_string(i));
		mList->AddElement(pTile);
	}
}
