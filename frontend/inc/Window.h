#pragma once
#include "View.h"
class WindowManager;

class Window
{
    private:
        //Имя окна
        std::string name;
        WindowManager* manager;
        //Текущий вид
        View* currentView;
        Context* context;
        void SetContext(Context* context);
        void SetManager(WindowManager* manager);
    public:
        Window(const std::string& name);
        ~Window();
        
        View* GetCurrentView() const;
        void SetCurrentView(View* view, bool autoClose = 0);
        
        //Берёт контекст из Context или если задан менеджер использует контекст заданый в менеджере
        Context* GetContext();
        WindowManager* GetManager();
        
        std::string GetName() const;

    friend class WindowManager;
    friend class Context;
};

