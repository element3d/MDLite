#ifndef __Application_BASE_H__
#define __Application_BASE_H__

#include <e3/Application.h>
#include <e3/FontManager.h>
#include <e3/i18n.h>


class ApplicationBase : public e3::Application
{
public:
    ApplicationBase(const std::string& applicationName, e3::EE3OS os, e3::EE3Target target, e3::Size2i windowSize, e3::Size2i resolution) 
		: e3::Application(applicationName, os, target, windowSize, resolution)
    {
        
    }
};

#endif // __Application_BASE_H__
