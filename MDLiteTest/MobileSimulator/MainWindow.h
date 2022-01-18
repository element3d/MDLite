#ifndef __MAIN_WINDOW__
#define __MAIN_WINDOW__

#include <e3/Window.h>
#include <Application.h>

class MainWindow : public e3::Window
{
public:
	MainWindow(e3::WindowCreateInfo* pWindowCreateInfo);

protected:
	virtual void OnRender() override;

protected:
	virtual void OnResize(int width, int height) override;
	virtual void OnMouseDown(e3::MouseEvent* pEvent) override;
	virtual void OnMouseUp(e3::MouseEvent* pEvent) override;
	virtual void OnMouseHover(e3::MouseEvent* pEvent) override;
	virtual void OnScroll(e3::MouseEvent* pEvent) override; 
	virtual void OnMouseWhell(e3::MouseEvent* pEvent) override;
	virtual void OnKey(e3::EKey key, int mods, unsigned short c) override;
};

#endif // __MAIN_WINDOW__
