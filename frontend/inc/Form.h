#pragma once
#include "View.h"

class Form : public View
{
    public:
        using View::View;
        Form(const std::string& tag);
};