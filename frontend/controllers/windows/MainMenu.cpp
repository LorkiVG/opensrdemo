#include <windows/MainMenu.h>

class MainEventHandler : public Rml::EventListener
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
    this->window = windowManager->AddWindow(path);
    Rml::Element* element = ;
    MyEventHandler* handler = new MyEventHandler();
    mainwindow->AddEventListener(new ButtonsEventHandler());
};
std::unique_ptr<BaseController> MainMenuControllerFactory::Create() 
{
    return std::make_unique<MainMenuController>();
};

bool MainMenuControllerValidator::ButtonsValidator(const std::string& input)
{
    
};