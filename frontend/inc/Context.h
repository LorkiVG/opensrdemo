#pragma once
#include <RmlUi_Backend.h>
#include "modules/inc/LOGManager.h"
#include "FormManager.h"
#include "WindowManager.h"

bool ProcessKeyDownShortcutsDefault(Rml::Context *context, Rml::Input::KeyIdentifier key, int key_modifier, float native_dp_ratio, bool priority);

/// @brief Класс "обёртка" над Rml::Context
/// @param context Ссылка на Rml::Context
/// @param keyDownCallback Указатель на callback для обработкки событий
/// @param windows std::map из окон Window.h
/// @param windowManagers std::map из оконнных менеджеров WindowManager.h
/// @param formManagers std::map из менеджеров форм FormManager.h
class Context
{

    private:
        // Да обёртка не наследованием, но если RmlUI соблюдали бы SOLID и использовали для создания контекста конструктор было бы иначе, а так мы вынуждены изощерятся
        Rml::Context *context;
        KeyDownCallback keyDownCallback;
        bool powerSave;
        std::map<std::string, Window*> windows;
        std::map<std::string, WindowManager*> windowManagers;
        std::map<std::string, FormManager*> formManagers;

    public:
        Context(std::string name, int width, int height, KeyDownCallback keyDownCallback = nullptr, bool powerSave = false);
        ~Context();
        //! Внимание данный метод временный для дебаггера
        Rml::Context *Get() const;

        /// @brief Получить имя
        std::string GetName() const;

        /// @brief Отгрузка всех документов
        void UnloadAllDocuments();
        /// @brief Снимает фокус с вида
        /// @param view Вид  
        void UnfocusDocument(View* view);

        /// @brief Загрузить документ(нужно в основном для View)
        /// @param path  
        /// @return Rml::ElementDocument*
        Rml::ElementDocument* LoadDocument(const fs::path& path);

        /// @brief Получить callback функцию для обработки событий
        /// @return KeyDownCallback
        KeyDownCallback GetKeyDownCallback();
        
        /// @brief Установка callback функции для обработкки событий
        /// @param keyDownCallback 
        void SetKeyDownCallback(KeyDownCallback keyDownCallback);

        bool GetPowerSave();
        void SetPowerSave(bool powerSave);

        /// @brief Добавить окно
        /// @param name Имя окна
        void AddWindow(Window* window);

        /// @brief Получить окно по имени
        /// @param name Имя окна
        Window* GetWindow(const std::string name) const;

        /// @brief Вырезать окно по имени и вернуть его
        /// @param name Имя окна
        Window* CutWindow(const std::string name);

        /// @brief Удалить окно по имени
        /// @param name Имя окна
        void DeleteWindow(const std::string name);


        /// @brief Добавить менеджер окон
        /// @param windowManager Манеджер окон
        void AddWindowManager(WindowManager* windowManager);

        /// @brief Получить менеджер окон
        /// @param name Имя менеджера окон
        /// @return Получаемый оконный менеджер
        WindowManager* GetWindowManager(const std::string name) const;

        /// @brief Вырезать менеджер окон и вернуть его
        /// @param name Имя менеджера окон
        /// @return Вырезаемый оконный менеджер
        WindowManager* CutWindowManager(const std::string name);

        /// @brief Удалить менеджер окон
        /// @param name Имя менеджера окона
        void DeleteWindowManager(const std::string name);

        /// @brief Добавить менеджер форм
        /// @param formManager Менеджер форм
        void AddFormManager(FormManager* formManager);

        /// @brief Получить менеджер форм
        /// @param name Имя менеджера форм
        /// @return Получаемый менеджер форм
        FormManager* GetFormManager(const std::string name) const;

        /// @brief Вырезать менеджер форм и вернуть его
        /// @param name Имя менеджера форм
        /// @return Вырезаемый менеджер форм
        FormManager* CutFormManager(const std::string name);

        /// @brief Удалить менеджер форм
        /// @param name Имя менеджера форм
        void DeleteFormManager(const std::string name);

        /// @brief Обработка событий указанных в KeyDawnCallback
        /// @param running Указатель на состояние главного цикла фронтенда
        void ProcessEvents(bool* running);
        /// @brief Обновление компонентов - Update components
        void Update();
        /// @brief Рендер - Render
        void Render();
};

extern Context* mainContext; 