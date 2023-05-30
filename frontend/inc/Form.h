#pragma once
#include "View.h"
class FormManager;

class Form : public View
{
    private:
        FormManager* manager;
    public:
        using View::View;
        Form(const std::string& name);

        void Load(fs::path);

        std::string GetName();
    friend class FormManager;
};