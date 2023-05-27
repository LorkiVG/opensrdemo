#include "Window.h"

Window::Window(const std::string& name)
{
    this->name = name;
    this->currentview = nullptr;

}

Window::~Window()
{
    
}

View* Window::getCurrentView() const
{
    return this->currentview;
}

void Window::setCurrentView(View* view)
{
    this->currentview = view;
}


std::string Window::GetName() const
{
    return this->name;
}