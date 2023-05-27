#pragma once
#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <map>
#include <string>
#include "modules/inc/FilePaths.h"

class Window : public Rml::ElementDocument 
{
    using Rml::ElementDocument::ElementDocument;
    Window(const std::string& tag);
};