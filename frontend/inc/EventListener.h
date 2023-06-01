#include <RmlUi/Core/EventListener.h>

class EventListener : public Rml::EventListener
{
public:
	EventListener(const Rml::String& value);
	virtual ~EventListener();

	/// @brief Посылаем в эвент-менеджер
	void ProcessEvent(Rml::Event& event) override;

	/// @brief При OnDetach уничтожаем текущий объект
	void OnDetach(Rml::Element* element) override;

private:
	Rml::String value;
};
