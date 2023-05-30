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
        
    protected:
        Rml::ElementDocument* view;
    public:
        //Нужно для более удобного назначения
        Context* context;
        
        View(const std::string& name);
        ~View();

        void Load(fs::path path);
        void Close();
};