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
        /// @brief Констуктор менеджера окон
        /// @param name Имя будущего менеджера окон
        WindowManager(const std::string& name);
        /// @brief Деструктор менеджера окон
        ~WindowManager();

        /// @brief Получить контекст в котором находится текущий менеджер окон
        /// @return Контекст или nullptr
        Context* GetContext();

        /// @brief Добавить окно в менеджер
        /// @param window Добавляемое окно
        void Add(Window* window);
        /// @brief Получить окно по его имени
        /// @param name Имя окна
        /// @return Получаемое окно
        Window* Get(const std::string& name) const;
        /// @brief Вырезать окно из менеджера(нужно чтоб допустим переместить окно в другой менеджер или подсоеденить к контексту напрямую)
        /// @param name Имя окна
        /// @return Вырезанное окно
        Window* Cut(const std::string& name);
        /// @brief Удалить окно из менеджера окон
        /// @param name Имя окна
        void Remove(const std::string& name);
        
        /// @brief Получить имя менеджера окон
        std::string GetName() const;
        
    friend class Context;
};