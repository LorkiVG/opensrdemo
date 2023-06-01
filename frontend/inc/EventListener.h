#include <RmlUi/Core/EventListener.h>

class EventListener : public Rml::EventListener
{
public:
	EventListener(const Rml::String& value);
	virtual ~EventListener();

	/// Посылаем в эвент-менеджер
	void ProcessEvent(Rml::Event& event) override;

	/// По документации тут надо уничтожать.
	void OnDetach(Rml::Element* element) override;

private:
	Rml::String value;
};
