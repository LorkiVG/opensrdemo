#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <map>
#include <string>
#include "LibPaths.h"


class WindowManager
{
    private:
        Rml::Context* context;
        std::map<const fs::path, Rml::ElementDocument*> windows;
    public:
        WindowManager(Rml::Context* context);
        Rml::ElementDocument* AddWindow(const fs::path path);
        Rml::ElementDocument* GetWindow(const fs::path path);
        void ShowWindow(const fs::path path);
        void HideWindow(const fs::path path);
        void CloseWindow(const fs::path path);
        
};
