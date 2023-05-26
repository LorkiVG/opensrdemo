#include <RmlUi/Core.h>
#include <string>
#include <map>
#include "LibPaths.h"
#include "FormManager.h"
#include "WindowManager.h"


class Context : public Rml::Context
{
    using Rml::Context::Context;
    private:
        std::map<const std::string, WindowManager*> windowmanagers;
        std::map<const std::string, FormManager*> formmanagers;
        
    public:
        ~Context();
        void AddWindowManager(WindowManager* window_manager);
        WindowManager* GetWindowManager(const std::string name);
        void RemoveWindowManager(const std::string name);

        void AddFormManager(FormManager* form_manager);
        FormManager* GetFormManager(const std::string name);
        void RemoveFormManager(const std::string name);
};