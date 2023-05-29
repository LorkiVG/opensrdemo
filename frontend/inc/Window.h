#pragma once
#include "View.h"
class WindowManager;

class Window
{
    private:
        //Имя окна
        std::string name;
        //Если не задан windowManager то используется в качестве контекста
        
        //Текущий вид
        View* currentView;


    public:
        //Нужно для более удобного и быстрого общения с оконным менеджером если он установлен если нет то используется Context 
        WindowManager* windowManager;
        Context* context;

        Window(const std::string& name);
        
        View* GetCurrentView() const;
        void SetCurrentView(View* view, bool autoClose = 0);
        
        //Берёт контекст из Сщ
        Context* GetContext();
        
        std::string GetName() const;
};