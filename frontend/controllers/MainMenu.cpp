#include <controllers/MainMenu.h>

class MainMenuControllerEventHandler : public Rml::EventListener
{
    public:
        virtual void ProcessEvent(Rml::Event& event)
        {
            MAINLOG->WriteStr("FOCUSED","\n");
            
        }
};


void MainMenuController::Initialize() 
{
    

    View* view = new View("mainmenu");
	mainWindow->SetCurrentView(view);
    
	view->Load(fs::path(UIPATH / fs::path("MainMenu.rml")));
    
    
    
    EventListenerInstancer event_listener_instancer;
	Rml::Factory::RegisterEventListenerInstancer(&event_listener_instancer);

    view->Show();
    Form* form = new Form("settings");
    mainFormManager->Add(form);

    form->Load(fs::path(UIPATH / fs::path("Settings.rml")));

    form->Show();

    
};
std::unique_ptr<BaseController> MainMenuControllerFactory::Create() 
{
    return std::make_unique<MainMenuController>();
};