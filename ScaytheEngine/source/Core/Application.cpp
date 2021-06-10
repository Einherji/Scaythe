//
// Created by matthiaso on 6/9/21.
//

#include "Application.h"

namespace Scaythe {
    Application::Application(const char* name)
    {
        Log::Init(name);
        appName = name;
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        S_CORE_TRACE("Application Starting");
        S_CORE_TRACE("Application Running");
    }
}