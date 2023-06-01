#pragma once
#include <RmlUi/Core/ElementDocument.h>
#include <RmlUi/Core/Event.h>
#include <RmlUi/Core/Types.h>
#include "modules/inc/LOG.h"
#include "modules/inc/Validator.h"

class EventHandler;

class EventManager
{
    public:
        /// Освобождает все обработчики событий
        static void Shutdown();

        /// Регистрируем новый обработчик событий
        /// @param[in] handler_name Имя будущего обработчика события
        /// @param[in] handler Сам обработчик EventHandler
        static void RegisterEventHandler(const Rml::String& handler_name, Rml::UniquePtr<EventHandler> handler);

        /// Стандартный обработчик событий
        /// @param[in] event Событие RmlUi создавшее данное событие 
        /// @param[in] value Значение события
        static void ProcessEvent(Rml::Event& event, const Rml::String& value);

private:
	EventManager();
	~EventManager();
};