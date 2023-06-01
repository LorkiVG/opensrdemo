#include "EventManager.h"
#include "EventHandler.h"
#include <RmlUi/Core/Context.h>
#include <RmlUi/Core/ElementDocument.h>
#include <RmlUi/Core/ElementUtilities.h>
#include "RouterManager.h"

// Обработчик событий для текущего экрана. Может быть nullptr если текущий экран не имеет какой-то функциональности.
static EventHandler* event_handler = nullptr;

// Обработчики событий в текущем менеджере
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

// Стандартный главный обработчик событий
void EventManager::ProcessEvent(Rml::Event& event, const Rml::String& value)
{
    //Подразделяем на команды строку
    Rml::StringList commands;
	Rml::StringUtilities::ExpandString(commands, value, ';');
    Validator* validator = new Validator("(\\w+)\\((.*?)\\)");
	for (size_t i = 0; i < commands.size(); ++i)
	{
        std::vector<std::string> matches = validator->GetMatches(commands[i]);
        if(matches[1] == "OpenForm")
        {
            router->GetRoute(matches[2])->Initialize();
        }
	}
    delete validator;
}