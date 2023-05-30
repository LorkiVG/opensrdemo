#include "View.h"

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
    this->view = context->Load(path.string());
}

void View::Close()
{
    this->view->Close();
}
