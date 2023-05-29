#pragma once
#include "View.h"
class WindowManager;

class Window
{
    private:
        std::string name;
        Context* windowManager;

        WindowManager* windowManager;

        View* currentview;


    public:
        Window(const std::string& name);
        
        void Window::SetWindowManager(WindowManager* windowManager);

        View* GetCurrentView() const;
        void SetCurrentView(View* view);
        
        Context* GetContext();
        void SetContext(Context* context);
        

        std::string GetName() const;
};
