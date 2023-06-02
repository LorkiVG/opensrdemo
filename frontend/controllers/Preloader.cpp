#include "controllers/Preloader.h"

void PreloaderController::Initialize() 
{
    View* view = new View("preloader");
    preloaderWindow->SetCurrentView(view);
    view->Load(fs::path(UIPATH / fs::path("Preloader.rml")));
    view->Hide();
};

void PreloaderController::Show()
{
    preloaderWindow->GetCurrentView()->Show();
}

void PreloaderController::UpdatePreloader()
{
    
}

void PreloaderController::PreHide()
{
    Rml::ElementList body;
    preloaderWindow->GetCurrentView()->GetElementsByTagName(body, "body");
    body[0]->SetClass("hide", 1);
    boost::asio::io_context io;
    boost::asio::deadline_timer t(io, boost::posix_time::milliseconds(1800));
    t.async_wait(&Hide);
    io.run();
}

void PreloaderController::Hide()
{
    preloaderWindow->GetCurrentView()->Hide();
}

std::unique_ptr<BaseController> PreloaderControllerFactory::Create()
{
    return std::make_unique<PreloaderController>();
}

std::unique_ptr<PreloaderController> mainPreloader;