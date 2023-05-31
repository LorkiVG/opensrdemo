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

        void AddEventListener(const Rml::String& event, Rml::EventListener* listener, bool in_capture_phase = false);
        void GetElementsByTagName(Rml::ElementList& elements, const std::string& tag);

        void PullToFront();
        void PushToBack();

        void Load(fs::path path);
        void Close();
        void Show(Rml::ModalFlag modalFlag = Rml::ModalFlag::None, Rml::FocusFlag focusFlag = Rml::FocusFlag::Auto);
        void Unload();

        
    friend class Window;
    friend class Context;
};