#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <map>
#include <string>
#include "FilePaths.h"

class Form : public Rml::ElementDocument 
{
    using Rml::ElementDocument::ElementDocument;
    Form(const std::string& tag);
};