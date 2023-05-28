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
        std::string name;
        Context* context;
        const Rml::ElementDocument* view;
    public:
        View(const std::string& name);
        ~View();

        std::string GetName();
};