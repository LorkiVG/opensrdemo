#pragma once
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
        std::thread loadingThread;
    public:
        void LoadResources();
        void Initialize() override;
};

class MainMenuControllerFactory : public BaseControllerFactory {
    public:
        std::unique_ptr<BaseController> Create() override;
};