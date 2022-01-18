
#ifndef MDCheckbox_H_
#define MDCheckbox_H_

#include "private/MDCheckboxBase.h"
#include "MDTheme.h"

class E3_EXPORT MDCheckbox : public MDCheckboxBase
{
	typedef std::function<void(bool)> OnChangeCallback;
public:
	MDCheckbox(e3::Element* pParent = nullptr);

	void Check();
	void Uncheck();
	bool IsChecked();
	void SetChecked(bool checked);

	void SetOnChangeCallback(OnChangeCallback c);

	virtual void Render() override;
public:
	virtual bool OnClick(e3::MouseEvent*) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

private:
	bool mChecked = false;
	e3::Animation* mAnimation = nullptr;
	OnChangeCallback mOnChangeCallback;
};

#endif // MDCheckbox_H_

