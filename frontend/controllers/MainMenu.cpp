#include <controllers/MainMenu.h>

class MainMenuControllerEventHandler : public Rml::EventListener
{
    public:
        virtual void ProcessEvent(Rml::Event& event)
        {
            MAINLOG->WriteStr("FOCUSED","\n");
            
        }
};


MainMenuControllerEventHandlerInstancer::MainMenuControllerEventHandlerInstancer()
{
};

MainMenuControllerEventHandlerInstancer::~MainMenuControllerEventHandlerInstancer() {

};

Rml::EventListener* MainMenuControllerEventHandlerInstancer::InstanceEventListener(const Rml::String& value, Rml::Element* element)
{
    MAINLOG->WriteStr(value,"\n");
    return new Rml::EventListener(value);
};


void MainMenuController::Initialize() 
{
    

    View* view = new View("mainmenu");
	mainWindow->SetCurrentView(view);
    
	view->Load(fs::path(UIPATH / fs::path("MainMenu.rml")));
    
    view->Show();
    
    Form* form = new Form("settings");
    mainFormManager->Add(form);

    form->Load(fs::path(UIPATH / fs::path("Settings.rml")));

    form->Show();

    Rml::Factory::RegisterEventListenerInstancer(new MainMenuControllerEventHandlerInstancer());
};
std::unique_ptr<BaseController> MainMenuControllerFactory::Create() 
{
    return std::make_unique<MainMenuController>();
};