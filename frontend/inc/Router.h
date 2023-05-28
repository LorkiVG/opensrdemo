#pragma once
#include <map>
#include <memory>
#include "controllers/Controller.h"
#include "controllers/MainMenu.h"
#include "controllers/Galaxy.h"
#include "controllers/Preloader.h"
#include "controllers/Settings.h"
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

