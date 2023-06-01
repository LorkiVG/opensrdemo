#include "EventManager.h"
#include "EventHandler.h"
#include <RmlUi/Core/Context.h>
#include <RmlUi/Core/ElementDocument.h>
#include <RmlUi/Core/ElementUtilities.h>
#include <RmlUi_Backend.h>

// The game's element context (declared in main.cpp).
extern Rml::Context* context;

// The event handler for the current screen. This may be nullptr if the current screen has no specific functionality.
static EventHandler* event_handler = nullptr;

// The event handlers registered with the manager.
using EventHandlerMap = Rml::SmallUnorderedMap<Rml::String, Rml::UniquePtr<EventHandler>>;
EventHandlerMap event_handlers;

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}

// Освобождает все обработчики событий
void EventManager::Shutdown()
{
	event_handlers.clear();
	event_handler = nullptr;
}

// Регистрирует новый обработчик событий
void EventManager::RegisterEventHandler(const Rml::String& handler_name, Rml::UniquePtr<EventHandler> handler)
{
	event_handlers[handler_name] = std::move(handler);
}

// Стандартный обработчик событий
void EventManager::ProcessEvent(Rml::Event& event, const Rml::String& value)
{
	Rml::StringList commands;
	Rml::StringUtilities::ExpandString(commands, value, ';');
	for (size_t i = 0; i < commands.size(); ++i)
	{
		Rml::StringList values;
		Rml::StringUtilities::ExpandString(values, commands[i], ' ');
        MAINLOG->WriteStr(value, "\n");
	}
}