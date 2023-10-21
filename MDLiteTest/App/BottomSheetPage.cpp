#include "BottomSheetPage.h"
#include <e3/Application.h>
#include "MDListTile.h"

BottomSheetPage::BottomSheetPage(e3::Element* pParent)
	: BottomSheetPageBase(pParent)
{
	mBack->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PopElement(new MDPopTransitionAnimation(this));
	});

	mShowButton->SignalOnClick.Connect([this](e3::MouseEvent*) {
		mBottomSheet->ShowModal();
	});

	for (int i = 0; i < 20; ++i)
	{
		MDListTile* pTile = new MDListTile();
		pTile->SetTitle("Item" + std::to_string(i));
		mList->AddElement(pTile);
	}
}
