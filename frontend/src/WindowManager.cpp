#include "WindowManager.h"

WindowManager::WindowManager(const std::string& name)
{
    this->name = name;
};

WindowManager::~WindowManager()
{
    for(std::map<const std::string, Window*>::iterator window = this->windows.begin(); window != this->windows.end();)
    {
        delete window->second;
        windows.erase(window);
    };
};

void WindowManager::SetContext(Context* context)
{
    this->context = context;
}

Context* WindowManager::GetContext()
{
    return this->context;
}

// Добавить окно
void WindowManager::Add(Window* window)  
{
    window->SetManager(this);
    this->windows[window->GetName()] = window;
};

// Получить форму
Window* WindowManager::Get(const std::string& name) const
{
    std::map<const std::string, Window*>::const_iterator window = this->windows.find(name);
    if (window != this->windows.end()) 
    {
        return window->second;
    }
    else
    {
        return nullptr;
    }
}

// Удалить форму
void WindowManager::Remove(const std::string& name) 
{
    std::map<const std::string, Window*>::iterator window = this->windows.find(name);
    if (window != this->windows.end()) 
    {
        delete window->second;
        this->windows.erase(window);
    }
}

std::string WindowManager::GetName() const
{
    return this->name;
};