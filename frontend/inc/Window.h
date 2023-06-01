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
        /// @brief Конструктор окна
        /// @param name Имя окна
        Window(const std::string& name);
        /// @brief Деструктор окна
        ~Window();
        
        /// @brief Получить текущий вид
        /// @return Текущий вид или nullptr, если окно не ещё имеет вида
        View* GetCurrentView() const;
        /// @brief Установить текущий вид 
        /// @param view Устанавливаемый текущий вид
        /// @param autoClose Параметр автоматического закрытия предыдущего текущего вида(допустим можно установить 0 если нужно вид переместить в другое окно)
        void SetCurrentView(View* view, bool autoClose = 1);
        
        /// @brief Получить контекст в котором находится окно (если есть менеджер окон то будет взят его контекст)
        /// @return Контекст или nullptr, если окно не имеет соеденения с контекстом
        Context* GetContext();
        /// @brief Получить менеджер окон
        /// @return Менеджер окон или nullptr, если окно не имеет менеджера
        WindowManager* GetManager();
        
        /// @brief Получить имя окна
        /// @return Имя окна
        std::string GetName() const;

    friend class WindowManager;
    friend class Context;
};

