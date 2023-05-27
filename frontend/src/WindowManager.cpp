
#include "WindowManager.h"

WindowManager::WindowManager(std::string name)
{
    this->name = name;
};

WindowManager::~WindowManager()
{
    for(std::map<const std::string, Window*>::iterator window = this->windows.begin(); window != this->windows.end();)
    {
        window->second->Close();
        delete window->second;
        windows.erase(window);
    };
};

// Добавить окно
void WindowManager::Add(Window* window)  
{
    this->windows[window->GetTitle()] = window;
};

// Получить форму
Window* WindowManager::Get(const std::string& name) 
{
    std::map<const std::string, Window*>::const_iterator window = this->windows.find(name);
    if (window != this->windows.end()) 
    {
        return window->second;
    }
}

// Удалить форму
void WindowManager::Remove(const std::string& name) 
{
    std::map<const std::string, Window*>::iterator window = this->windows.find(name);
    if (window != this->windows.end()) 
    {
        window->second->Close();
        delete window->second;
        this->windows.erase(window);
    }
}

std::string WindowManager::GetName() 
{
    return name;
};