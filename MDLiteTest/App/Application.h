#ifndef __Application_H__
#define __Application_H__

#include "private/ApplicationBase.h"

class Application : public ApplicationBase
{
public:
    Application(const std::string& applicationName, e3::EE3OS os, e3::EE3Target target, e3::Size2i windowSize, e3::Size2i resolution);

    virtual bool OnBack() override;
public:
	void OnResize(float width, float height) override;
};

#endif // __Application_H__
