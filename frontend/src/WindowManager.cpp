#include "LibPaths.h"
#include "WindowManager.h"

WindowManager::WindowManager(Rml::Context* context)
{
    this->context = context;
};

// Загрузить страницу
Rml::ElementDocument* WindowManager::AddWindow(const fs::path path)  
{
    Rml::ElementDocument* window = this->context->LoadDocument(path.string());
    this->windows[path] = window;
    if (window) {
        window->Hide();
    }
    return window;
}

Rml::ElementDocument* WindowManager::GetWindow(const fs::path path) 
{
    return this->windows[path];
}

// Отобразить страницу
void WindowManager::ShowWindow(const fs::path path) 
{
    auto it = this->windows.find(path);
    if (it != this->windows.end()) {
        it->second->Show();
    }
}

// Скрыть страницу
void WindowManager::HideWindow(const fs::path path) 
{
    auto it = this->windows.find(path);
    if (it != this->windows.end()) {
        it->second->Hide();
    }
}

// Закрыть страницу
void WindowManager::CloseWindow(const fs::path path)
{
    auto it = this->windows.find(path);
    if (it != this->windows.end()) {
        it->second->Close();
        this->windows.erase(it);
    }
}