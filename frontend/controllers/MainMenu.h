#pragma once
#include <string>
#include <memory>
#include "controllers/Controller.h"

class MainMenuControllerEventHandlerInstancer : public Rml::EventListenerInstancer
{
public:
	MainMenuControllerEventHandlerInstancer();
	virtual ~MainMenuControllerEventHandlerInstancer();

	Rml::EventListener* InstanceEventListener(const Rml::String& value, Rml::Element* element) override;

};

class MainMenuController : public BaseController {
    private:
        Rml::ElementDocument* window;
        
    public:
        void Initialize() override;
};

class MainMenuControllerFactory : public BaseControllerFactory {
    public:
        std::unique_ptr<BaseController> Create() override;
};