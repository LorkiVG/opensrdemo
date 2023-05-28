#pragma once
#include <RmlUi/Core.h>
#include <string>
#include <map>
#include "FormManager.h"
#include "WindowManager.h"
#include "modules/inc/LOG.h"


class Context : public Rml::Context
{
    using Rml::Context::Context;
    private:
        std::map<std::string, WindowManager*> windowmanagers;
        std::map<std::string, FormManager*> formmanagers;
        
    public:
        ~Context();
        void AddWindowManager(WindowManager* windowmanager);
        WindowManager* GetWindowManager(const std::string name) const;
        void RemoveWindowManager(const std::string name);

        void AddFormManager(FormManager* formmanager);
        FormManager* GetFormManager(const std::string name) const;
        void RemoveFormManager(const std::string name);

        View* LoadDocument(const fs::path& path);
};