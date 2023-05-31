#include "Window.h"
#include "WindowManager.h"

Window::Window(const std::string& name)
{
    this->name = name;
    this->currentView = nullptr;
    this->manager = nullptr;
    this->context = nullptr;
}

Window::~Window()
{
    if(this->currentView)
    {
        delete this->currentView;
    }
}

Context* Window::GetContext()
{
    if(this->manager) 
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

WindowManager* Window::GetManager()
{
    return this->manager;
}

void Window::SetManager(WindowManager* manager)
{
    this->manager = manager;
}

View* Window::GetCurrentView() const
{
    return this->currentView;
}


void Window::SetCurrentView(View* view, bool autoClose)
{
    if(autoClose && this->currentView)
    {
        delete this->currentView;
    }
    view->SetWindow(this);
    this->currentView = view;
}

std::string Window::GetName() const
{
    return this->name;
}

