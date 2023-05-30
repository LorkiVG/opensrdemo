#pragma once
#include "Window.h"

class WindowManager
{
    private:
        std::string name;
        Context* context;
        std::map<std::string, Window*> windows;
        void SetContext(Context* context);
    public:
        WindowManager(const std::string& name);
        ~WindowManager();

        Context* GetContext();

        void Add(Window* window);
        Window* Get(const std::string& name) const;
        void Remove(const std::string& name);
        
        std::string GetName() const;
    friend class Context;
};