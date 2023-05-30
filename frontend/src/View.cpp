#include "View.h"
#include "Window.h"
#include "Context.h"

View::View(const std::string& name)
{
    this->window = nullptr;
};

View::~View()
{
    this->view->Close();
}


void View::Load(fs::path path)
{
    Context* context = this->window->GetContext();
    if(context != nullptr)
    {
        this->view = context->LoadDocument(path);
    }
}

void View::Close()
{
    this->view->Close();
}

