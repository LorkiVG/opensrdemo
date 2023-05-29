#include "Window.h"

Window::Window(const std::string& name)
{
    this->name = name;
    this->currentView = nullptr;
    this->windowManager = nullptr;
}


View* Window::GetCurrentView() const
{
    return this->currentView;
}


void Window::SetCurrentView(View* view, bool autoClose)
{
    if(autoClose && this->currentView != nullptr)
    {
        this->currentView->Close();
    }
    
    if(this->windowManager != nullptr)
    {
        this->currentView = view;
    }
    else 
    {

    }
   
}

Context* Window::GetContext()
{
    return this->context;
}

std::string Window::GetName() const
{
    return this->name;
}
