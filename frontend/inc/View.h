#pragma once
#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <map>
#include "modules/inc/FilePaths.h"
#include <string>
class Context;
class Window;

class View
{
    private:
        
    protected:
        Rml::ElementDocument* view;
    public:
        Window* window;
        
        View(const std::string& name);
        ~View();

        void Load(fs::path);
        void Close();
};