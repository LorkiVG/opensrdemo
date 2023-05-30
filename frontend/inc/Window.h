#pragma once
#include "View.h"
class Window
{
    private:
        //Имя окна
        std::string name;
        //Если не задан windowManager то используется в качестве контекста
        
        //Текущий вид
        View* currentView;


    public:
        Context* context;
        Window(const std::string& name);
        
        View* GetCurrentView() const;
        void SetCurrentView(View* view, bool autoClose = 0);
        
        //Берёт контекст из Context или если задан менеджер использует контекст заданый в менеджере
        Context* GetContext();
        
        std::string GetName() const;
};