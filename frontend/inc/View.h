#pragma once
#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <map>
#include <string>
#include "modules/inc/FilePaths.h"

class View
{
    private:
        const Rml::ElementDocument* view;
    public:
        using Rml::ElementDocument::ElementDocument;
        View(const std::string& tag);
        ~View();
};