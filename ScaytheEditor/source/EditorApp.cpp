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