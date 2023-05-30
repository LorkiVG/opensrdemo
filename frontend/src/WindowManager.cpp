#include "WindowManager.h"

WindowManager::WindowManager(const std::string& name)
{
    this->name = name;
};

WindowManager::~WindowManager()
{
    for(std::map<const std::string, Window*>::iterator window = this->windows.begin(); window != this->windows.end(); ++window)
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

// Добавить окно - Add window
void WindowManager::Add(Window* window)  
{
    window->SetManager(this);
    this->windows[window->GetName()] = window;
};

// Получить окно - Get window
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

//Вырезать окно - Cut window
Window* WindowManager::Cut(const std::string& name)
{
    std::map<const std::string, Window*>::iterator window = this->windows.find(name);
    if (window != this->windows.end()) 
    {
        window->second->SetManager(nullptr);
        this->windows.erase(window);
        return window->second;
    }
    else 
    {
        return nullptr;
    }
}

// Удалить форму - Delete Form
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