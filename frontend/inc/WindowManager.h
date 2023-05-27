#pragma once
#include "Window.h"

class WindowManager
{
    private:
        std::string name;
        std::map<const std::string, Window*> windows;

    public:
        WindowManager(const std::string& name);
        ~WindowManager();

        void Add(Window* window);
        Window* Get(const std::string& name) const;
        void Remove(const std::string& name);
        
        std::string GetName() const;
};
