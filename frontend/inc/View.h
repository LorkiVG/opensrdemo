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
        void SetWindow(Window* window);
    protected:
        Rml::ElementDocument* view;
    public:
        
        View(const std::string& name);
        ~View();

        Context* View::GetContext();

        void Load(fs::path path);
        void Close();
        void Unload();


    friend class Window;
};