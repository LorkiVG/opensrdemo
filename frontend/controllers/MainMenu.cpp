#include <controllers/MainMenu.h>


void MainMenuController::Initialize() 
{
    View* view = new View("mainmenu");
	mainWindow->SetCurrentView(view);

    EventListenerInstancer event_listener_instancer;
	Rml::Factory::RegisterEventListenerInstancer(&event_listener_instancer);

	view->Load(fs::path(UIPATH / fs::path("MainMenu.rml")));    

    view->Show();
};
std::unique_ptr<BaseController> MainMenuControllerFactory::Create() 
{
    return std::make_unique<MainMenuController>();
};