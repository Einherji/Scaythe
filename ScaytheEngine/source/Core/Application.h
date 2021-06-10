//
// Created by matthiaso on 6/9/21.
//

#ifndef SCAYTHE_APPLICATION_H
#define SCAYTHE_APPLICATION_H

#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Log.h"

namespace Scaythe {
    class Application {
    public:
        Application(const char* name);
        ~Application();
        void Run();
        inline const char* GetName() { return appName; }

    private:
        const char* appName;
        bool running;
    };

    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void ErrorCallback(int error, const char* description);

    // To be defined in the client (editor, sandbox, etc...)
    Application* CreateApplication();
}



#endif //SCAYTHE_APPLICATION_H
