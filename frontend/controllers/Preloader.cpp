#include "controllers/Preloader.h"

void PreloaderController::Initialize() 
{
    preloaderWindow = new Window("preloader");
    mainContext->AddWindow(preloaderWindow);
    View* view = new View("preloader");
    preloaderWindow->SetCurrentView(view);
    view->Load(fs::path(UIPATH / fs::path("Preloader.rml")));
    this->preloaderBarStrip = view->GetElementById("preloaderBarStrip");
};

Window* PreloaderController::GetPreloaderWindow()
{
    return this->preloaderWindow;
}

void PreloaderController::Show()
{
    this->preloaderWindow->GetCurrentView()->Show(Rml::ModalFlag::Modal, Rml::FocusFlag::Auto);
}

void PreloaderController::UpdatePreloader(int percent)
{
    this->preloaderBarStrip->SetProperty("transition", "width 1s");
    this->preloaderBarStrip->SetProperty("width", to_string(percent) + "%");
}



void PreloaderController::Hide()
{
    Rml::Element* body = preloaderWindow->GetCurrentView()->GetElementById("preloader");
    body->SetClass("hide", 1);

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    preloaderWindow->GetCurrentView()->Hide();
}

std::unique_ptr<BaseController> PreloaderControllerFactory::Create()
{
    return std::make_unique<PreloaderController>();
}

std::unique_ptr<PreloaderController> mainPreloader;