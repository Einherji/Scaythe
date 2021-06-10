//
// Created by matthiaso on 6/10/21.
//

#ifndef SCAYTHE_STARTUP_H
#define SCAYTHE_STARTUP_H

#include "Application.h"


int main(int argc, char** argv)
{
    // external function defined on client application
    auto app = Scaythe::CreateApplication();
    app->Run();
    delete app;
}

#endif //SCAYTHE_STARTUP_H
