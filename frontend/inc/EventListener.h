#include <RmlUi/Core/EventListener.h>

class EventListener : public Rml::EventListener
{
    public:
        EventListener(const Rml::String& value);
        virtual ~EventListener();

        void ProcessEvent(Rml::Event& event) override;

        void OnDetach(Rml::Element* element) override;

private:
	Rml::String value;
};
