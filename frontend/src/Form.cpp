#include "Form.h"
#include "FormManager.h"
#include "Context.h"

Form::Form(const std::string& name) : View(name)
{
    this->manager = nullptr;
};

void Form::Load(fs::path path)
{
    if(this->manager != nullptr)
    {
        Context* context = this->manager->GetContext();
        if(context != nullptr)
        {
            this->view = context->LoadDocument(path);
        }
    }
    
}

void Form::SetManager(FormManager* manager)
{
    this->manager = manager;
}

std::string Form::GetName()
{
    return this->view->GetTitle();
}