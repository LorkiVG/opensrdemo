#pragma once
#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <string>
#include <map>
#include "modules/inc/FilePaths.h"
class Context;

class View
{
    private:
        Window* window;
    protected:
        Rml::ElementDocument* view;
    public:
        
        View(const std::string& name);
        ~View();

        void Load(fs::path path);
        void Close();
    friend class Window;
};