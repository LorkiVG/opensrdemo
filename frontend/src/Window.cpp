#include "Window.h"

Window::Window(const std::string& name)
{
    this->name = name;
    this->currentview = nullptr;
}

View* Window::GetCurrentView() const
{
    return this->currentview;
}

void Window::SetCurrentView(View* view)
{
    this->currentview = view;
}


std::string Window::GetName() const
{
    return this->name;
}