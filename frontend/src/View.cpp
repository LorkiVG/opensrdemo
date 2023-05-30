#include "View.h"
#include "Context.h"

View::View(const std::string& name)
{
    this->context = nullptr;
};

View::~View()
{
    this->view->Close();
}


void View::Load(fs::path path)
{
    this->view = this->context->LoadDocument(path);
}

void View::Close()
{
    this->view->Close();
}

