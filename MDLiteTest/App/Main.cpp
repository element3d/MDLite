#include "Main.h"
#include <e3/Application.h>
#include "AppBarPage.h"
#include "ButtonsPage.h"
#include "BottomNavigationBarPage.h"
#include "BottomSheetPage.h"
#include "DrawerPage.h"
#include "NavigationRailPage.h"
#include "DialogPage.h"
#include "MenuPage.h"
#include "SelectionControlsPage.h"
#include "SlidersPage.h"
#include "TabsPage.h"
#include "TextFieldsPage.h"
#include "ProgressIndicatorPage.h"
#include "ListPage.h"
#include "SnackbarPage.h"
#include "MDTheme.h"

Main::Main(e3::Element* pParent)
	: MainBase(pParent)
{
	mDarkModeSwitch->SetOnChangeCallback([this](bool checked) {
		if (!mDarkTheme) 
		{
			mDarkTheme = new MDTheme();
			mDarkTheme->PrimaryColor = new MDColor(MDColors::Primary::Get("200"));
			mDarkTheme->OnPrimary = new MDColor(0, 0, 0, 255);
			mDarkTheme->AppBarTheme.BackgroundColor = new MDColor(glm::mix(glm::vec4(36, 30, 48, 255), glm::vec4(255), 0.1));
			mDarkTheme->AppBarTheme.TextColor = new MDColor(MDColors::Primary::Get("200"));
			mDarkTheme->AppBarTheme.IconColor = new MDColor(MDColors::Primary::Get("200"));
			mDarkTheme->ScaffoldBackgroundColor = new MDColor(glm::mix(glm::vec4(36, 30, 48, 255), glm::vec4(255), 0.05));
			mDarkTheme->Background = new MDColor(36, 30, 48, 255);
			mDarkTheme->OnBackground = new MDColor(255);
			mDarkTheme->OnSurface = new MDColor(255);
			mDarkTheme->Surface = new MDColor(glm::mix(glm::vec4(36, 30, 48, 255), glm::vec4(255), 0.05));
			mDarkTheme->BottomNavigationBarTheme.BackgroundColor = new MDColor(glm::mix(glm::vec4(36, 30, 48, 255), glm::vec4(255), 0.1));
			mDarkTheme->BottomNavigationBarTheme.SelectedItemColor = new MDColor(MDColors::Primary::Get("200"));
			mDarkTheme->BottomNavigationBarTheme.UnselectedItemColor = new MDColor(MDColors::Primary::Get("200"));
			mDarkTheme->DialogTheme.BackgroundColor = new MDColor(36, 30, 48, 255);
		}
		if (checked)
			MDTheme::Set(mDarkTheme);
		else
			MDTheme::SetDefault();
	});
	

	mAppBarPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		AppBarPage* pAppBarPage = new AppBarPage();
		GetApplication()->PushElement(pAppBarPage, false, new MDPushTransitionAnimation(pAppBarPage));
	});

	mButtonPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		ButtonsPage* pButtonsPage = new ButtonsPage();
		GetApplication()->PushElement(pButtonsPage, false, new MDPushTransitionAnimation(pButtonsPage));
	});

	mBottomNavBarPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		BottomNavigationBarPage* pBottomNavigationBarPage = new BottomNavigationBarPage();
		GetApplication()->PushElement(pBottomNavigationBarPage, false, new MDPushTransitionAnimation(pBottomNavigationBarPage));
	});

	mBottomSheetPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		BottomSheetPage* pBottomSheetPage = new BottomSheetPage();
		GetApplication()->PushElement(pBottomSheetPage, false, new MDPushTransitionAnimation(pBottomSheetPage));
	});

	mMenuPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		MenuPage* pMenuPage = new MenuPage();
		GetApplication()->PushElement(pMenuPage, false, new MDPushTransitionAnimation(pMenuPage));
	});

	mProgressIndicatorsPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PushElement(new ProgressIndicatorPage());
	});

	mSelectionControlsPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PushElement(new SelectionControlsPage());
	});

	mSlidersPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PushElement(new SlidersPage());
	});

	mTextFieldsPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PushElement(new TextFieldsPage());
	});

	mTabsPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PushElement(new TabsPage());
	});

	mNavRailPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PushElement(new NavigationRailPage());
	});

	mDrawerPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PushElement(new DrawerPage());
	});

	mDialogPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		DialogPage* pDialogPage = new DialogPage();
		GetApplication()->PushElement(pDialogPage, false,  new MDPushTransitionAnimation(pDialogPage));
	});

	mListPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		ListPage* pListPage = new ListPage();
		GetApplication()->PushElement(pListPage, false, new MDPushTransitionAnimation(pListPage));
	});

	mSnackbarPage->SignalOnClick.Connect([this](e3::MouseEvent*) {
		SnackbarPage* pSnackbarPage = new SnackbarPage();
		GetApplication()->PushElement(pSnackbarPage, false, new MDPushTransitionAnimation(pSnackbarPage));
	});
}
