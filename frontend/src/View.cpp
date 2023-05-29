#include "View.h"

View::View(const std::string& name)
{
    this->window = nullptr;
};

View::~View()
{
    this->view->Close();
}


//Загрузка по файловому пути, загрузка происходит на контекст по установлему пути в context
void View::Load(fs::path)
{
}

void View::Close()
{
    this->view->Close();
}
