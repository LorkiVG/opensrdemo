#include <Router.h>


void Router::AddRoute(const fs::path path, std::unique_ptr<BaseControllerFactory> factory) 
{
    factories[path] = std::move(factory);
}

void Router::RemoveRoute(const fs::path path) 
{
    factories.erase(path);
}

std::unique_ptr<BaseController> Router::GetRoute(const fs::path path) 
{
    auto it = factories.find(path);
    if (it != factories.end()) {
        return it->second->Create();
    } 
    else 
    {
        return nullptr;
    }        
};

namespace MainRouter
{
    void Init()
    {
        router.AddRoute(fs::path(UIPATH.string() + "MainMenu.rml"), std::make_unique<MainMenuControllerFactory>());
        router.AddRoute(fs::path(UIPATH.string() + "Settings.rml"), std::make_unique<SettingsControllerFactory>());
        router.AddRoute(fs::path(UIPATH.string() + "Preloader.rml"), std::make_unique<PreloaderControllerFactory>());
    }
}