#include <controllers/MainMenu.h>

class MainMainControllerEventHandler : public Rml::EventListener
{
public:
    virtual void ProcessEvent(Rml::Event& event)
    {
        if (event == "click")
        {
            // обработка клика
        }
    }
};


void MainMenuController::Initialize(WindowManager* windowManager, const fs::path path) 
{

};
std::unique_ptr<BaseController> MainMenuControllerFactory::Create() 
{
    return std::make_unique<MainMenuController>();
};