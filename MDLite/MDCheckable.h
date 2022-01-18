#ifndef __MDCHECKABLE__
#define __MDCHECKABLE__

#include <e3.h>
#include <functional>
#include <vector>

class MDRadioGroup;
class E3_EXPORT MDCheckable 
{
	typedef std::function<void(bool)> OnChangeCallback;
public:
	MDCheckable() {}

	void SetGroup(MDRadioGroup* pGroup);

	virtual void Check();
	virtual void Uncheck();
	virtual bool IsChecked();

	void SetOnChangeCallback(OnChangeCallback c);
protected:
	bool mChecked = false;
	std::vector<OnChangeCallback> mOnChangeCallbacks;
};

#endif // !__MDCHECKABLE__
