#ifndef EDITOR_ENTRY
#define EDITOR_ENTRY

#include <Scaythe.h>
#include <Core/Startup.h>

namespace Scaythe {
    class EditorApplication : public Application {
    public:
        EditorApplication() : Application("EDITOR")
        {
            S_TRACE("Editor application initialized");
            // somehow hook in with imgui and create the interface (extend Layer class)
        }
        ~EditorApplication()
        {

        }
    };

    Application* CreateApplication()
    {
        return new EditorApplication();
    }
}

#endif