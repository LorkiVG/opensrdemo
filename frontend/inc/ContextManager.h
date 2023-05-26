#include <RmlUi/Core.h>
#include <string>
#include <map>
#include "LibPaths.h"
#include "FormManager.h"
#include "WindowManager.h"

class Context : public Rml::Context
{
    private:
        ~Context();
    public:
        void GetWindowManager(const std::string name);
        void AddWindowManager(const WindowManager* window_manager);
        void RemoveWindowManager(std::string name);

        void GetFormManager(const std::string name);
        void AddFormManager(const FormManager* form_manager);
        void RemoveFormManager(const std::string name);
};
class ContextManager
{
    private:
        std::map<const std::string, Context*> contexts;
    public:
        ContextManager();
        ~ContextManager();
        void New(const Context* context);
        
        void New(const std::string name);
        Context* Get(const std::string name) const;
        void Remove(const std::string name);
        
};