#pragma once
#include "View.h"
class FormManager;

class Form : public View
{
    private:
        std::string name;
        FormManager* manager;
    public:
        using View::View;
        /// @brief Констурктор формы 
        /// @param name Имя формы
        Form(const std::string& name);

        /// @brief Установить менеджер форм (нужно обязательно его установить так как контекст будет взят именно оттуда)
        /// @param manager Менеджер форм
        void SetManager(FormManager* manager);

        /// @brief Загрузить документ для вида формы
        /// @param path Путь к документу
        void Load(fs::path path);

        /// @brief Получить имя формы
        /// @return Имя формы 
        std::string GetName();
    friend class FormManager;
};