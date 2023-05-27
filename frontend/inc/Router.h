#pragma once
#include <map>
#include <memory>
#include "Controller.h"
#include "windows/MainMenu.h"
#include "windows/Galaxy.h"
#include "windows/Preloader.h"
#include "forms/Settings.h"
class Router {
    private:
        std::string name;
        std::map<fs::path, std::unique_ptr<BaseControllerFactory>> factories;

    public:
        void AddRoute(const fs::path path, std::unique_ptr<BaseControllerFactory> factory);
        void RemoveRoute(const fs::path path);

        std::unique_ptr<BaseController> GetRoute(const fs::path documentName);

        std::string GetName();
};


//TODO Сделать нормальный RouterManager, то что ниже временно
namespace MainRouter {
    Router router;
    void Init();
}

