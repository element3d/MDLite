
#ifndef __APP_LOCALE_H__
#define __APP_LOCALE_H__

#include <e3/LocaleBase.h>

enum class ELocale 
{
    en,
};

class AppLocale : public e3::LocaleBase
{
public:
    AppLocale() : e3::LocaleBase()
    {
                mLocales[(int)ELocale::en] = "locale/en.json";

    }
};

#endif // __APP_LOCALE_H__

