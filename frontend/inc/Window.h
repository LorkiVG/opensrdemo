#pragma once
#include "View.h"
class WindowManager;

class Window
{
    private:
        std::string name;
        WindowManager* windowManager;
        View* currentview;

    public:
        Window(const std::string& name);

        View* GetCurrentView() const;
        void SetCurrentView(View* view);

        std::string GetName() const;
};
