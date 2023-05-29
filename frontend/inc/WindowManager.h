#pragma once
#include "Window.h"

class WindowManager
{
    private:
        std::string name;
        
        std::map<std::string, Window*> windows;

    public:
        //Нужно для более удобного и быстрого общения в контекстом
        Context* context;

        WindowManager(const std::string& name);
        ~WindowManager();

        void Add(Window* window);
        Window* Get(const std::string& name) const;
        void Remove(const std::string& name);
        
        std::string GetName() const;
};