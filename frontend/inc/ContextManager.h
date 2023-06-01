#pragma once
#include "Context.h"

class ContextManager
{
    private:
        std::string name;
        std::map<const std::string, Context*> contexts;

    public:
        ContextManager(const std::string& name);
        ~ContextManager();


        /// @brief Добавляет новый контекст в contexts
        /// @param context Добавляемый контекст
        void Add(Context* context);
        /// @brief Получить контекст
        /// @param name Имя контекста
        /// @return Возращаемый контекст
        Context* Get(const std::string& name) const;
        /// @brief Удаляет коннекст
        /// @param name Имя коннекста
        void Remove(const std::string& name);
        
        /// @brief Получить имя
        /// @return Возращаемое имя
        std::string GetName() const;

        /// @brief Обработка событий всех контекстов указанных в их KeyDawnCallback
        /// @param running Указатель на состояние главного цикла фронтенда
        void ProcessEventsAll(bool* running);
        /// @brief Обновление всех контекстов
        void UpdateAll();
        /// @brief Рендеринг всех контекстов
        void RenderAll();
};