
#ifndef MDSnackbar_H_
#define MDSnackbar_H_

#include "private/MDSnackbarBase.h"

class E3_EXPORT MDSnackbar : public MDSnackbarBase
{
public:
	MDSnackbar(e3::Element* pParent = nullptr);
	~MDSnackbar();

	void Show();
	void Hide();

private:
	e3::Animation* mAnimation = nullptr;
	e3::Animation* mHideAnimation = nullptr;
	e3::Timeout* mHideTimeout = nullptr;
};

#endif // MDSnackbar_H_

