#pragma once
#include "View.h"
class FormManager;

class Form : public View
{
    private:
        std::string name;
        FormManager* manager;
    public:
        using View::View;
        Form(const std::string& name);

        void SetManager(FormManager* manager);

        void Load(fs::path);

        std::string GetName();
    friend class FormManager;
};