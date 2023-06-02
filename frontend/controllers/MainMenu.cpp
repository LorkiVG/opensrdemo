#include <controllers/MainMenu.h>
#include <controllers/Preloader.h>


void MainMenuController::LoadResources()
{
    std::lock_guard<std::mutex> lock(contextManagerMutex);
    
    //Дополнительная "видимость" загрузки ресурсов, нужно чтоб предлоадер был показан хотяб пару секунд
    mainWindow->GetCurrentView()->Show(Rml::ModalFlag::None, Rml::FocusFlag::None);
    mainPreloader->UpdatePreloader(40);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mainPreloader->UpdatePreloader(70);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mainPreloader->UpdatePreloader(100);
    mainPreloader->Hide();
}


void MainMenuController::Initialize() 
{
      
    EventListenerInstancer event_listener_instancer;
	Rml::Factory::RegisterEventListenerInstancer(&event_listener_instancer);

    mainPreloader->UpdatePreloader(0);

    //Показываем предлоадер тут чтоб RmlUI было что рендерить и не возникла "гонка потоков"
    mainPreloader->Show();

    View* view = new View("mainmenu");
	mainWindow->SetCurrentView(view);
    view->Load(fs::path(UIPATH / fs::path("MainMenu.rml")));  
    

    mainPreloader->UpdatePreloader(20);

    //Для оптимизации запускаем загрузку ресурсов в отдельном потоке
	loadingThread = std::thread(&LoadResources, this);
    loadingThread.detach();
};
std::unique_ptr<BaseController> MainMenuControllerFactory::Create() 
{
    return std::make_unique<MainMenuController>();
};


