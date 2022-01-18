
#ifndef MDBottomSheet_H_
#define MDBottomSheet_H_

#include "private/MDBottomSheetBase.h"

class E3_EXPORT MDBottomSheet : public MDBottomSheetBase
{
public:
	MDBottomSheet(e3::Element* pParent = nullptr);

	void Show();
	void ShowModal();
	void Hide();

	bool IsShown();

	virtual void AddElement(e3::Element* pElement) override;
public:
	virtual bool OnClick(e3::MouseEvent* pEvent) override;

private:
	void Show(bool showModal);

private:
	bool mIsShown = false;;
	e3::Element* mContent = nullptr;
	e3::Animation* mAnimation = nullptr;
};

#endif // MDBottomSheet_H_

