#pragma once
#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <map>
#include "modules/inc/FilePaths.h"
#include <string>
class Context; 

class View
{
    private:
        Context* context;
    protected:
        std::string name;
        Rml::ElementDocument* view;
    public:
        View(const std::string& name);
        ~View();

        void Load(fs::path);
        void SetContext(Context* context);
        Context* GetContext();

        std::string GetName();
};