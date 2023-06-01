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
        
        FormManager(const std::string& name);
        ~FormManager();

        Context* GetContext() const;

        /// @brief Добавить форму в менеджер
        /// @param form Сама форма
        void Add(Form* form);
        /// @brief Получить форму по имени
        /// @param name Имя формы 
        /// @return Получаемая форма
        Form* Get(const std::string& name) const;
        /// @brief Удалить форму по имени
        /// @param name Имя формы
        void Remove(const std::string& name); 
        
        std::string GetName() const;
    friend Context;
};