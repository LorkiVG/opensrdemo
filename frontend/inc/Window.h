#pragma once
#include "View.h"
class WindowManager;

class Window
{
    private:
        std::string name;
        View* currentView;
        void SetContext(Context* context);
        Context* context;
        void SetManager(WindowManager* manager);
        WindowManager* manager;
    public:
        Window(const std::string& name);
        ~Window();
        
        View* GetCurrentView() const;
        void SetCurrentView(View* view, bool autoClose = 0);
        
        Context* GetContext();
        WindowManager* GetManager();
        
        std::string GetName() const;

    friend class WindowManager;
    friend class Context;
};

