
#ifndef MDDialog_H_
#define MDDialog_H_

#include "private/MDDialogBase.h"
#include "MDTheme.h"

class E3_EXPORT MDDialog : public MDDialogBase
{
public:
	MDDialog(e3::Element* pParent = nullptr);

	void Show();
	void Hide();

	virtual void Render() override;

public:
	virtual void SetWidth(const e3::Dim& dim) override;
	virtual void SetHeight(const e3::Dim& dim) override;
	virtual void AddElement(e3::Element* pElement) override;
	virtual bool OnClick(e3::MouseEvent* pEvent) override;

private:
	bool mOpened = false;
	e3::Animation* mAnimation = nullptr;
};

#endif // MDDialog_H_

