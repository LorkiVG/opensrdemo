#pragma once
#include "View.h"

class Window
{
    private:
        std::string name;
        View* currentview;

    public:
        Window(const std::string& name);

        View* GetCurrentView() const;
        void SetCurrentView(View* view);

        std::string GetName() const;
};
