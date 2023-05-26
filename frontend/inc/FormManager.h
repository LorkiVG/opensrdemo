#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <map>
#include <string>
#include "LibPaths.h"


class FormManager
{
    private:
        Rml::Context* context;
        std::map<const fs::path, Rml::ElementDocument*> forms;
    public:
        FormManager(Rml::Context* context);
        Rml::ElementDocument* AddForm(const fs::path path);
        Rml::ElementDocument* GetForm(const fs::path path);
        void ShowForm(const fs::path path);
        void HideForm(const fs::path path);
        void CloseForm(const fs::path path);
        
};