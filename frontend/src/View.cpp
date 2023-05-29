#include "View.h"

View::View(const std::string& name)
{
    this->name = name;
    this->context = nullptr;
};

View::~View()
{
    this->view->Close();
}

std::string View::GetName()
{
    return this->name;
}


void View::SetContext(Context* context)
{
    this->context = context;
}

Context* View::GetContext()
{
    return this->context;
}

void View::Load(fs::path)
{
}