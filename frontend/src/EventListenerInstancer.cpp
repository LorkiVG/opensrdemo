#include "EventListenerInstancer.h"
#include "EventListener.h"

EventListenerInstancer::EventListenerInstancer()
{
}

EventListenerInstancer::~EventListenerInstancer()
{
}

// Создаём новый экземпляр обработчика события
Rml::EventListener* EventListenerInstancer::InstanceEventListener(const Rml::String& value, Rml::Element* /*element*/)
{
	return new EventListener(value);
}
