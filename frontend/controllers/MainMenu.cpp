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
    this->window = windowManager->Add(path);
    Rml::Element* element = ;
    MainMainControllerEventHandler* handler = new MainMainControllerEventHandler();
    mainwindow->AddEventListener(handler);
};
std::unique_ptr<BaseController> MainMenuControllerFactory::Create() 
{
    return std::make_unique<MainMenuController>();
};