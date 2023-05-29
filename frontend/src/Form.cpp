#include "Form.h"

Form::Form(const std::string& name) : View(name)
{
    
};

void Form::Load(fs::path)
{
    
}

std::string Form::GetName()
{
    return this->view->GetTitle();
}