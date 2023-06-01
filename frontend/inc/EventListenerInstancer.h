#include <RmlUi/Core/EventListenerInstancer.h>
#include "modules/inc/LOG.h"

class EventListenerInstancer : public Rml::EventListenerInstancer
{
    public:
        EventListenerInstancer();
        virtual ~EventListenerInstancer();

        Rml::EventListener* InstanceEventListener(const Rml::String& value, Rml::Element* element) override;
};