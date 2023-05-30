#pragma once
#include "View.h"

class Form : public View
{

    public:
        Context* context;
        using View::View;
        Form(const std::string& name);

        void Load(fs::path);

        std::string GetName();
};