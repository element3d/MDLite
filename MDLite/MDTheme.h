#ifndef __MD_THEME__
#define __MD_THEME__

#include "MDColors.h"

class MDAppBarTheme 
{
public:
	MDAppBarTheme();

public:
	MDColor* BackgroundColor;
	MDColor* TextColor;
	MDColor* IconColor;
};

class MDNavigationRailTheme
{
public:
	MDNavigationRailTheme();

public:
	MDColor* BackgroundColor;
	MDColor* SelectedItemColor;
	MDColor* UnselectedItemColor;
};

class MDBottomNavigationBarTheme
{
public:
	MDBottomNavigationBarTheme();

public:
	MDColor* BackgroundColor;
	MDColor* SelectedItemColor;
	MDColor* UnselectedItemColor;
};

class MDDialogTheme
{
public:
	MDDialogTheme();

public:
	MDColor* BackgroundColor;
};

class E3_EXPORT MDTheme
{
public:
	static MDTheme* Get();
	static void Set(MDTheme* pTheme);
	static void SetDefault();

	MDTheme();

public:
	MDColor* PrimaryColor;
	MDColor* OnPrimary;
	MDColor* Background;
	MDColor* OnBackground;
	MDColor* Surface;
	MDColor* OnSurface;
	MDColor* ScaffoldBackgroundColor;
	MDAppBarTheme AppBarTheme;
	MDBottomNavigationBarTheme BottomNavigationBarTheme;
	MDNavigationRailTheme NavigationRailTheme;
	MDDialogTheme DialogTheme;
private:
	static MDTheme* sCurrentTheme;
	static MDTheme* sDefaultTheme;
};

#endif // !__MD_THEME__
