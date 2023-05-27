#pragma once
#include "View.h"

class Window
{
    private:
        std::string name;
        View* currentview;

    public:
        View* getCurrentView() const;
        void setCurrentView(View* view);

        Window(const std::string& name);
        ~Window();

        std::string GetName() const;
};
