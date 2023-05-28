#pragma once
#include <RmlUi/Core.h>
#include <RmlUi_Backend.h>
#include <string>
#include <map>

#include "FormManager.h"
#include "WindowManager.h"
#include "modules/inc/LOG.h"

bool ProcessKeyDownShortcutsDefault(Rml::Context *context, Rml::Input::KeyIdentifier key, int key_modifier, float native_dp_ratio, bool priority);

// Класс "обёртка" над Rml::Context
class Context
{
private:
    // Да обёртка не наследованием, но если RmlUI соблюдали бы SOLID и использовали для создания контекста конструктор было бы иначе, а так мы вынуждены изощерятся
    Rml::Context *context;
    KeyDownCallback keyDownCallback;
    bool powerSave;
    std::map<std::string, WindowManager *> windowmanagers;
    std::map<std::string, FormManager *> formmanagers;

public:
    Context(std::string name, int width, int height, KeyDownCallback keyDownCallback = nullptr, bool powerSave = true);
    ~Context();
    //! Внимание данный метод временный для дебаггера
    Rml::Context *Get() const;

    std::string GetName() const;

    void Context::UnloadAllDocuments();

    KeyDownCallback GetKeyDownCallback();
    void SetKeyDownCallback(KeyDownCallback keyDownCallback);

    void AddWindowManager(WindowManager *windowmanager);
    WindowManager *GetWindowManager(const std::string name) const;
    void RemoveWindowManager(const std::string name);

    void AddFormManager(FormManager *formmanager);
    FormManager *GetFormManager(const std::string name) const;
    void RemoveFormManager(const std::string name);

    void ProcessEvents(bool* running);
    void Update();
    void Render();
};