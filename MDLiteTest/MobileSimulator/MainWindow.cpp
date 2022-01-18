#include "MainWindow.h"
#include <Application.h>

MainWindow::MainWindow(e3::WindowCreateInfo* pWindowCreateInfo) : e3::Window(pWindowCreateInfo)
{
	Application* pApp = new Application("E3Demo", e3::EE3OS::Windows, e3::EE3Target::Desktop, pWindowCreateInfo->Size, pWindowCreateInfo->Resoluction);
	SetApplication(pApp);
}

void MainWindow::OnRender()
{
	
}

void MainWindow::OnResize(int width, int height)
{
	e3::Window::OnResize(width, height);
}

void MainWindow::OnMouseDown(e3::MouseEvent* pEvent)
{
	e3::Window::OnMouseDown(pEvent);
}

void MainWindow::OnMouseUp(e3::MouseEvent* pEvent)
{
	e3::Window::OnMouseUp(pEvent);
}

void MainWindow::OnMouseHover(e3::MouseEvent* pEvent)
{
	e3::Window::OnMouseHover(pEvent);
}

void MainWindow::OnScroll(e3::MouseEvent* pEvent)
{
	e3::Window::OnScroll(pEvent);
}

void MainWindow::OnMouseWhell(e3::MouseEvent* pEvent)
{
	e3::Window::OnMouseWhell(pEvent);
}

void MainWindow::OnKey(e3::EKey key, int mods, unsigned short c)
{
	e3::Window::OnKey(key, mods, c);
}