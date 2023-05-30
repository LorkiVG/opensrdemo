#include "Window.h"
#include "WindowManager.h"

Window::Window(const std::string& name)
{
    this->name = name;
    this->currentView = nullptr;
}

Window::~Window()
{
    if(this->currentView != nullptr)
    {
        delete this->currentView;
    }
}

Context* Window::GetContext()
{
    if(this->manager != nullptr) 
    {
        return this->manager->GetContext();
    }
    else 
    {
        return this->context;
    }
}

void Window::SetContext(Context* context)
{
    this->context = context;
}

void Window::SetContext(Context* context)
{
    this->context = context;
}

View* Window::GetCurrentView() const
{
    return this->currentView;
}


void Window::SetCurrentView(View* view, bool autoClose)
{
    if(autoClose && this->currentView != nullptr)
    {
        delete this->currentView;
    }
    view->window = this;
    this->currentView = view;
}

std::string Window::GetName() const
{
    return this->name;
}
