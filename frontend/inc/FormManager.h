#pragma once
#include "Form.h"

class FormManager
{
    private:
        std::string name;
        std::map<std::string, Form*> forms;
        Context* context;
        void SetContext(Context* context);
    public:
        /// @brief Конструктор менеджера форм
        /// @param name Имя будущего менеджера форм
        FormManager(const std::string& name);
        /// @brief Деструктор менеджера форм
        ~FormManager();

        /// @brief Получить контекст формы
        /// @return Контекст или nullptr, если контекст не установлен
        Context* GetContext() const;

        /// @brief Добавить форму в менеджер
        /// @param form Сама форма
        void Add(Form* form);
        /// @brief Получить форму по имени
        /// @param name Имя формы 
        /// @return Получаемая форма или nullptr, если форма не найдена
        Form* Get(const std::string& name) const;
        /// @brief Удалить форму по имени
        /// @param name Имя формы
        void Remove(const std::string& name); 
        
        /// @brief Получить имя менеджера форм
        /// @return Имя менеджера форм
        std::string GetName() const;
    friend Context;
};