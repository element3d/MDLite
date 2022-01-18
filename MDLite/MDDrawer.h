
#ifndef MDDrawer_H_
#define MDDrawer_H_

#include "private/MDDrawerBase.h"

class E3_EXPORT MDDrawer : public MDDrawerBase
{
public:
	MDDrawer(e3::Element* pParent = nullptr);

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

#endif // MDDrawer_H_

