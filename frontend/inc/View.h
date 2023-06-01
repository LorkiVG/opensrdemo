#pragma once
#include <RmlUi/Debugger.h>
#include <RmlUi/Core.h>
#include <string>
#include <map>
#include "modules/inc/FilePaths.h"
#include <boost/algorithm/string/replace.hpp>

class Context;
class Window;

class View
{
    private:
        Window* window;
        void SetWindow(Window* window);
    protected:
        Rml::ElementDocument* view;
    public:
        /// @brief Конструктор вида
        /// @param Имя вида
        View(const std::string& name);
        
        /// @brief Деструктор вида
        ~View();

        /// @brief Получить контекст в котором находится данный вид
        /// @return Указатель на получаемый конекст
        Context* GetContext();

        /// @brief Добавить слушатель событий 
        /// @param event Название события точнее можно глянуть тут https://developer.mozilla.org/ru/docs/Web/Events
        /// @param listener Объект прослушивателя событий
        void AddEventListener(const Rml::String& event, Rml::EventListener* listener, bool in_capture_phase = false);
        
        /// @brief Получить элементы по имени тега
        /// @param event Указатель на список куда будут сохранены элементы
        /// @param tag Имя тега
        void GetElementsByTagName(Rml::ElementList& elements, const std::string& tag);

        /// @brief Поднять вид выше всех других в отображении
        void PullToFront();
        /// @brief Опустить вид ниже всех других в отображении
        void PushToBack();

        /// @brief Загрузить документ для вида
        /// @param path Путь к файлу документа
        void Load(fs::path path);

        /// @brief Закрыть текущий вид(но так как задумывается что View просто расширяет Rml:::ElementDocument то лучше использовать Window, а не закрывать текущйи документ во View и открывать новый )
        void Close();

        /// @brief Показать вид
        /// @param modalFlag Флаг модального окна
        /// @param focusFlag Флаг фокуса
        void Show(Rml::ModalFlag modalFlag = Rml::ModalFlag::None, Rml::FocusFlag focusFlag = Rml::FocusFlag::Auto);

        
    friend class Window;
    friend class Context;
};