#pragma once
#include <RmlUi_Backend.h>
#include "modules/inc/LOG.h"
#include "FormManager.h"
#include "WindowManager.h"

bool ProcessKeyDownShortcutsDefault(Rml::Context *context, Rml::Input::KeyIdentifier key, int key_modifier, float native_dp_ratio, bool priority);

// Класс "обёртка" над Rml::Context
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
    Context(std::string name, int width, int height, KeyDownCallback keyDownCallback = nullptr, bool powerSave = true);
    ~Context();
    //! Внимание данный метод временный для дебаггера
    Rml::Context *Get() const;

    std::string GetName() const;

    void UnloadAllDocuments();
    void UnfocusDocument(View* view);

    //Загрузить документ(нужно в основном для View) - Load document(mostly needed for View)
    Rml::ElementDocument* LoadDocument(const fs::path& path);

    //Получить callback функцию для обработки событий - Get callback function for handling events
    KeyDownCallback GetKeyDownCallback();
    //Установка callback функции для обработкки событий - Set callback function for handling events
    void SetKeyDownCallback(KeyDownCallback keyDownCallback);

    bool GetPowerSave();
    void SetPowerSave(bool powerSave);

    //Добавить окно - Add window
    void AddWindow(Window* window);
    //Получить окно - Get window
    Window* GetWindow(const std::string name) const;
    //Вырезать окно и вернуть его - Cut window and return it
    Window* CutWindow(const std::string name);
    //Удалить окно - Delete window
    void DeleteWindow(const std::string name);

    //Добавить менеджер окон - Add window manager
    void AddWindowManager(WindowManager* windowmanager);
    //Получить менеджер окон - Get window manager
    WindowManager* GetWindowManager(const std::string name) const;
    //Вырезать менеджер окон и вернуть его - Cut window manager and return it
    WindowManager* CutWindowManager(const std::string name);
    //Удалить менеджер окон - Delete window manager
    void DeleteWindowManager(const std::string name);

    //Добавить менеджер форм - Add form manager
    void AddFormManager(FormManager* formmanager);
    //Получить менеджер форм - Get form manager
    FormManager* GetFormManager(const std::string name) const;
    //Вырезать менеджер форм и вернуть его - Cut form manager and return it
    FormManager* CutFormManager(const std::string name);
    //Удалить менеджер форм - Delete form manager
    void DeleteFormManager(const std::string name);

    //Обработка событий указанных в KeyDawnCallback -  Process events specified in keyDownCallback
    void ProcessEvents(bool* running);
    //Обновление компонентов - Update components
    void Update();
    //Рендер - Render
    void Render();
};