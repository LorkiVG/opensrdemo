#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <map>
#include <string>
#include "LibPaths.h"

class Window : public Rml::ElementDocument 
{
    using Rml::ElementDocument::ElementDocument;
    Window(const std::string& tag);
};