#include "EventListener.h"
#include "EventManager.h"

EventListener::EventListener(const Rml::String& value)
{
    this->value = value;
}

EventListener::~EventListener()
{
}

// Посылаем в эвент-менеджер
void EventListener::ProcessEvent(Rml::Event& event)
{
	EventManager::ProcessEvent(event, value);
}

// По документации тут надо уничтожать.
void EventListener::OnDetach(Rml::Element* RMLUI_UNUSED_PARAMETER(element))
{
	RMLUI_UNUSED(element);
	delete this;
}
