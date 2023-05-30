#pragma once
#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <string>
#include <map>
#include "modules/inc/FilePaths.h"
class Context;
class Window;

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

        Context* GetContext();

        void Load(fs::path path);
        void Close();
        void Show();
        void Unload();

        void GetElementsByTagName(Rml::ElementList& elements, const std::string& tag);
    friend class Window;
};