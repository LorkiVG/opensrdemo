#include "EventListener.h"
#include "EventManager.h"

EventListener::EventListener(const Rml::String& value)
{
    this->value = value;
}

EventListener::~EventListener()
{
}

/// @brief Посылаем в эвент-менеджер
/// @param event Указатель на эвент
void EventListener::ProcessEvent(Rml::Event& event)
{
	EventManager::ProcessEvent(event, this->value);
}

/// По документации тут надо уничтожать.
void EventListener::OnDetach(Rml::Element* RMLUI_UNUSED_PARAMETER(element))
{
	RMLUI_UNUSED(element);
	delete this;
}
